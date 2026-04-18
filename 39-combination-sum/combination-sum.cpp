class Solution {
public:
    void solve(int i, vector<int>& candidates, int target,
               vector<vector<int>>& ans, vector<int>& recurse) {
        if (i == candidates.size()) {

            if (target == 0) {
                ans.push_back(recurse);
            }

            return;
        }

        if (candidates[i] <= target) {
            recurse.push_back(candidates[i]);

            solve(i, candidates, target - candidates[i], ans, recurse);

            recurse.pop_back();
        }

        solve(i + 1, candidates, target, ans, recurse);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> recurse;

        solve(0, candidates, target, ans, recurse);

        return ans;
    }
};