/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

void dfs(TreeNode* root , int level , vector<long long >&sum , vector<int>& count){

    if(root == NULL) return ;

    if(level == sum.size()){
        sum.push_back(root->val) ;
        count.push_back(1) ;
    }else{
        sum[level] += root->val ;
        count[level]++ ;
    }

    dfs(root->left , level + 1 , sum , count) ;
    dfs(root->right , level + 1 , sum , count) ;
}
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<long long> sum ; 
        vector<int> count ;

        dfs(root , 0 , sum , count ) ;
        vector<double> ans ;

        for(int i = 0 ; i< sum.size() ; i++){
            ans.push_back((double)sum[i]/count[i]) ;
        } 

        return ans ; 
    }
};