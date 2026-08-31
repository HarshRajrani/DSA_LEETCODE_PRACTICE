class Solution {
public:

    int solve(vector<int>& nums, int curr_idx, int prev_idx,
              int n, vector<vector<int>>& dp) {

        // Base case
        if (curr_idx >= n)
            return 0;

        // Memoization
        if (dp[curr_idx][prev_idx + 1] != -1)
            return dp[curr_idx][prev_idx + 1];

        int take = 0;

        // Take current element
        if (prev_idx == -1 ||
            nums[curr_idx] % nums[prev_idx] == 0) {

            take = 1 + solve(
                nums,
                curr_idx + 1,
                curr_idx,
                n,
                dp
            );
        }

        // Skip current element
        int skip = solve(
            nums,
            curr_idx + 1,
            prev_idx,
            n,
            dp
        );

        return dp[curr_idx][prev_idx + 1] =
            max(take, skip);
    }


    vector<int> largestDivisibleSubset(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<vector<int>> dp(
            n,
            vector<int>(n + 1, -1)
        );

        // Calculate the maximum length
        solve(nums, 0, -1, n, dp);

        // Reconstruction
        vector<int> ans;

        int curr_idx = 0;
        int prev_idx = -1;

        while (curr_idx < n) {

            bool canTake =
                (prev_idx == -1 ||
                 nums[curr_idx] % nums[prev_idx] == 0);

            if (canTake) {

                int take = 1;

                if (curr_idx + 1 < n) {
                    take += dp[curr_idx + 1][curr_idx + 1];
                }

                int skip = 0;

                if (curr_idx + 1 < n) {
                    skip = dp[curr_idx + 1][prev_idx + 1];
                }

                // If taking gives optimal answer
                if (take >= skip) {
                    ans.push_back(nums[curr_idx]);
                    prev_idx = curr_idx;
                }
            }

            curr_idx++;
        }

        return ans;
    }
};