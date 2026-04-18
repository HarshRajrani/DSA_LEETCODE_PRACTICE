class Solution {
public:
    void solve(int idx, vector<int>& nums, vector<vector<int>>& ans,
               vector<int>& de) {

        ans.push_back(de);
        for (int i = idx; i < nums.size(); i++) {

            if (i != idx && nums[i] == nums[i - 1])
                continue;

            de.push_back(nums[i]);

            solve(i + 1, nums, ans, de);

            de.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> de;
        sort(nums.begin(), nums.end());
        solve(0, nums, ans, de);

        return ans;
    }
};