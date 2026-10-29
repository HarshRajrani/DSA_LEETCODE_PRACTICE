class Solution { 
public: 
    int n; 
     
    vector<vector<int>> graph; 
 
    vector<int> tin, tout, eulerTour; 
 
    vector<int> segTree; 
 
    vector<int> depth; 
 
    vector<vector<int>> ancestorTable; 
    int cols; 
 
    int time; 
 
    void dfs(int node, int dep, int parent, string& s) { 
        depth[node] = dep; // Store the depth of the current node.
        ancestorTable[node][0] = parent; // Store its immediate parent.

        tin[node] = time; // Entry time of the node in the Euler Tour.
        eulerTour[time] = (1 << (s[node] - 'a')); // Set the bit corresponding to the node's character.
         
        time++; // Move to the next Euler Tour position.
        for(int& child : graph[node]) { 
            if(child == parent) { 
                continue; // Avoid visiting the parent again.
            } 
 
            dfs(child, dep + 1, node, s); 
        } 
 
        tout[node] = time; // Exit time of the node in the Euler Tour.
        eulerTour[time] = (1 << (s[node] - 'a')); // Store the character again when leaving the node.
         
        time++; 
    } 
 
    // Segment Tree: Build {for XOR}. 
    void buildSegTree(int i, int l, int r, vector<int>& eulerTour) { 
        if(l == r) { 
            segTree[i] = eulerTour[l]; // Leaf stores the character mask at this position.
            return; 
        } 
 
        int mid = l + (r - l) / 2; 
 
        buildSegTree(2 * i + 1, l, mid, eulerTour); 
        buildSegTree(2 * i + 2, mid + 1, r, eulerTour); 
 
        // XOR the children to get the mask for the entire range.
        segTree[i] = segTree[2 * i + 1] ^ segTree[2 * i + 2]; 
    } 
 
    // Segment Tree: Point update {for XOR}. 
    void updateSegTree(int idx, int val, int i, int l, int r) { 
        if(l == r) { 
            segTree[i] = val; // Update the leaf representing Euler Tour position idx.
            return; 
        } 
 
        int mid = l + (r - l) / 2; 
 
        // idx is the Euler Tour position; i is the current Segment Tree index.
        if(idx <= mid) updateSegTree(idx, val, 2 * i + 1, l, mid); 
 
        else updateSegTree(idx, val, 2 * i + 2, mid + 1, r); 
 
        // Recalculate the XOR mask after updating the child.
        segTree[i] = segTree[2 * i + 1] ^ segTree[2 * i + 2]; 
    } 
 
    // Segment Tree: Search. 
    int querySegTree(int st, int end, int i, int l, int r) { 
        if(l > end || r < st) return 0; // No overlap: XOR identity is 0.
 
        if(l >= st && r <= end) return segTree[i]; // Complete overlap: return the stored XOR.
 
        int mid = l + (r - l) / 2; 
        // Combine the XOR results from both children.
        return querySegTree(st, end, 2 * i + 1, l, mid) ^ querySegTree(st, end, 2 * i + 2, mid + 1, r); 
    } 
 
 
    void buildAncestorTable() { 
        // ancestorTable[node][i] stores the 2^i-th ancestor of node.
        for(int i = 1; i < cols; i++) { 
            for(int node = 0; node < n; node++) { 
                if(ancestorTable[node][i - 1] != -1) { 
                    // Find the 2^i-th ancestor using two jumps of size 2^(i-1).
                    ancestorTable[node][i] = ancestorTable[ancestorTable [node] [i - 1] ] [i - 1]; 
                } 
            } 
        } 
    } 

    // Get LCA using Binary Lifting.
    int getLCA(int u, int v) { 
        // Make u the deeper node.
        if(depth[u] < depth[v]) swap(u, v); 
 
        int diff = depth[u] - depth[v]; 
 
        // Lift u until both nodes have the same depth.
        for(int j = 0; j < cols; j++) { 
            if(diff & (1 << j)) { 
                u = ancestorTable[u][j]; 
            } 
        } 
 
        if(u == v) return u; // One node is an ancestor of the other.
 
        // Lift both nodes while their ancestors remain different.
        for(int j = cols - 1; j >= 0; j--) { 
            if(ancestorTable[u][j] != ancestorTable[v][j]) { 
                u = ancestorTable[u][j]; 
                v = ancestorTable[v][j]; 
            } 
        } 
 
        return ancestorTable[u][0]; // Their parent is the LCA.
    } 
 
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) { 
        this->n = n; 
 
        graph.assign(n, {}); // Initialize the adjacency list.
        tin.assign(n, 0); 
        tout.assign(n, 0); 
        depth.assign(n, 0); 
        eulerTour.assign(2 * n, 0); // Store entry and exit positions for every node.
 
        // Build the undirected tree.
        for(auto& edge : edges) { 
            graph[edge[0]].push_back(edge[1]); 
 
            graph[edge[1]].push_back(edge[0]); 
        } 
 
        cols = log2(n) + 1; // Number of binary-lifting levels.
        ancestorTable.assign(n, vector<int>(cols, -1)); 
         
        // Let node 0 be the root.
        time = 0; 
        dfs(0, 0, -1, s); 
 
        // Build the Segment Tree over the Euler Tour array.
        // Its size is approximately 4 * (2 * n) = 8 * n.
        segTree.resize(8 * n, 0); 
        buildSegTree(0, 0, 2 * n - 1, eulerTour); 
 
        buildAncestorTable(); 
 
        vector<bool> res; 
         
        for(string& querie : queries) { 
            stringstream ss(querie); 
         
            string type; 
            ss >> type; 
 
            if(type == "update") { // Update the character of a node.
                int node; 
                char c; 
                ss >> node >> c; 
 
                int charVal = (1 << (c - 'a')); // Convert the new character into a bitmask.
 
                s[node] = c; // Update the character in the string.
 
                // Update both entry and exit positions in the Euler Tour.
                updateSegTree(tin[node], charVal, 0, 0, 2 * n - 1); 
                updateSegTree(tout[node], charVal, 0, 0, 2 * n - 1); 
            } 
            else { // Query whether the path between u and v can form a palindrome.
                int u, v; 
                ss >> u >> v; 
 
                int lcaNode = getLCA(u, v); // Find the lowest common ancestor.
                char ch = s[lcaNode]; 
                int charVal = (1 << (ch - 'a')); // Bitmask of the LCA's character.
 
                // XOR the root-to-u and root-to-v masks.
                // The LCA's character is included in both masks, so XOR it once more
                // to ensure it appears exactly once in the final path mask.
                int mask = querySegTree(0, tin[u], 0, 0, 2 * n - 1) ^ 
                           querySegTree(0, tin[v], 0, 0, 2 * n - 1) ^ 
                           charVal; 
 
                // A palindrome is possible if at most one character has an odd frequency.
                // In a bitmask, this means zero or one bits are set.
                bool isPalindromePossible = ((mask) & (mask - 1)) == 0; 
 
                res.push_back(isPalindromePossible); 
            } 
        } 
 
        return res;
    } 
};