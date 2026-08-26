class Solution {
public:
    int solve(int idx, int buy, vector<int>& prices, int n,
              vector<vector<int>>& dp) {

        //  base case

        if (idx >= n)
            return 0;

        if (dp[idx][buy] != -1)
            return dp[idx][buy];
        //  recurrence case

        if (buy == 1) {
            return dp[idx][buy] =
                       max(-prices[idx] + solve(idx + 1, 0, prices, n, dp),
                           0 + solve(idx + 1, 1, prices, n, dp));
        }

        return dp[idx][buy] =
                   max(prices[idx] + solve(idx + 2, 1, prices, n, dp),
                       solve(idx + 1, 0, prices, n, dp));
    }
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return solve(0, 1, prices, n, dp);
    }
};