class Solution {
public:

    int solve(vector<int>& nums, int curr_idx,
              int prev, int n,
              vector<vector<int>>& dp) {

        // Base case
        if(curr_idx >= n)
            return 0;

        // Memoization
        if(dp[curr_idx][prev + 1] != -1)
            return dp[curr_idx][prev + 1];

        // Not take is always possible
        int not_taken =
            solve(nums, curr_idx + 1, prev, n, dp);

        int taken = 0;

        // Take only if increasing
        if(prev == -1 || nums[curr_idx] > nums[prev]) {

            taken =
                1 + solve(nums, curr_idx + 1,
                          curr_idx, n, dp);
        }

        return dp[curr_idx][prev + 1] =
            max(taken, not_taken);
    }

    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> dp(
            n, vector<int>(n + 1, -1)
        );

        return solve(nums, 0, -1, n, dp);
    }
};