class Solution {
public:
    void solve(int idx, vector<int>& arr, int target, vector<vector<int>>& ans,
               vector<int>& des) {

        if (target == 0) {
            ans.push_back(des);
            return;
        }

        for (int i = idx; i < arr.size(); i++) {

            if (i > idx && arr[i] == arr[i - 1])
                continue;

            if (arr[i] > target)
                break;

            des.push_back(arr[i]);

            solve(i + 1, arr, target - arr[i], ans, des);

            des.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> des;

        solve(0, candidates, target, ans, des);

        return ans;
    }
};