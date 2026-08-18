class Solution {
public:
    int solve(vector<int>& coins, int target, int idx,
              vector<vector<int>>& dp) {

        // Base case
        if (target == 0)
            return 0;

        if (idx == 0) {
            if (target % coins[0] == 0)
                return target / coins[0];

            return 1e9;
        }

        // DP
        if (dp[idx][target] != -1)
            return dp[idx][target];

        // Don't take current coin
        int not_taken = solve(coins, target, idx - 1, dp);

        // Take current coin
        int taken = 1e9;

        if (coins[idx] <= target) {
            taken = 1 + solve(coins, target - coins[idx], idx, dp);
        }

        return dp[idx][target] = min(taken, not_taken);
    }

    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = solve(coins, amount, n - 1, dp);

        return ans == 1e9 ? -1 : ans;
    }
};