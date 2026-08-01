class Solution {
public:
    int solve(vector<int>& nums, int idx, int start, vector<int>& dp) {
        if (idx < start) return 0;
        if (idx == start) return nums[start];

        if (dp[idx] != -1) return dp[idx];

        int take = nums[idx] + solve(nums, idx - 2, start, dp);
        int notTake = solve(nums, idx - 1, start, dp);

        return dp[idx] = max(take, notTake);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];

        // Case 1: Rob from house 0 to n-2
        vector<int> dp1(n, -1);
        int ans1 = solve(nums, n - 2, 0, dp1);

        // Case 2: Rob from house 1 to n-1
        vector<int> dp2(n, -1);
        int ans2 = solve(nums, n - 1, 1, dp2);

        return max(ans1, ans2);
    }
};