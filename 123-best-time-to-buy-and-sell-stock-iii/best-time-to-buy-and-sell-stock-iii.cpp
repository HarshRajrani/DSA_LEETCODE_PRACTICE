class Solution {
public:
    int solve(int idx, int buy, int cap, vector<int>& prices, int n,
              vector<vector<vector<int>>>& dp) {

        //  base case

        if (idx == n || cap == 0)
            return 0;

        if (dp[idx][buy][cap] != -1)
            return dp[idx][buy][cap];

        //  recurrence case

        if (buy == 1) {
           return  dp[idx][buy][cap] =
                max(-prices[idx] + solve(idx + 1, 0, cap, prices, n, dp),
                                  0 + solve(idx + 1, 1, cap, prices, n, dp));
        } 
             return dp[idx][buy][cap] =
               max( prices[idx] + solve(idx + 1, 1, cap-1, prices, n , dp),
                                  solve(idx + 1, 0, cap, prices, n, dp)) ;
        
    }
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(3, -1)));

        return solve(0, 1, 2, prices, n, dp);
    }
};