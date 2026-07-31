class Solution {
public:
    int solve(vector<int>& nums, int idx, vector<int>& dp) {

        // base case
        if (idx < 0)
            return 0;
        if (idx == 0)
            return nums[0];

        if (dp[idx] != -1)
            return dp[idx];

        int take = nums[idx] + solve(nums, idx - 2, dp);

        int not_take = solve(nums, idx - 1, dp);

        return dp[idx] = max(take, not_take);
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n + 1, -1);

        return solve(nums, n - 1, dp);
    }
};