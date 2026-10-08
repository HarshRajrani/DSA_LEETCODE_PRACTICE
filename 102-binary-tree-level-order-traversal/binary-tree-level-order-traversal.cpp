class Solution {
public:

    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        dfs(root, 0, ans);

        return ans;
    }

    void dfs(TreeNode* root, int level, vector<vector<int>>& ans) {

        if (root == NULL)
            return;

        if (level == ans.size())
            ans.push_back({});

        ans[level].push_back(root->val);

        dfs(root->left, level + 1, ans);
        dfs(root->right, level + 1, ans);
    }
};