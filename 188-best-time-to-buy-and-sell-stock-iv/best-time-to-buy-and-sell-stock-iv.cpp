class Solution {
public:

    int solve(int idx, int buy, int cap,
              vector<int>& prices, int n,
              vector<vector<vector<int>>>& dp) {

        // base case
        if(idx == n || cap == 0)
            return 0;

        if(dp[idx][buy][cap] != -1)
            return dp[idx][buy][cap];

        // recurrence
        if(buy == 1) {

            // Buy
            int buyStock =
                -prices[idx] + solve(idx + 1, 0, cap, prices, n, dp);

            // Don't buy
            int notBuy =
                solve(idx + 1, 1, cap, prices, n, dp);

            return dp[idx][buy][cap] = max(buyStock, notBuy);
        }

        // Sell
        int sell =
            prices[idx] + solve(idx + 1, 1, cap - 1, prices, n, dp);

        // Don't sell
        int notSell =
            solve(idx + 1, 0, cap, prices, n, dp);

        return dp[idx][buy][cap] = max(sell, notSell);
    }

    int maxProfit(  int k ,vector<int>& prices) {

        int n = prices.size();

       // maximum number of transactions

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(2,
                vector<int>(k + 1, -1)
            )
        );

        return solve(0, 1, k, prices, n, dp);
    }
};