class Solution {
public:
     int solve(vector<int>& prices , int idx ,int  buy ,int  fee , int n , vector<vector<int>>& dp ){

        //  base case 

        if( idx >= n) return 0 ; 

        if(dp[idx][buy] != -1) return dp[idx][buy] ;

        // reccurence 

        if(buy){
            return dp[idx][buy] = max(- prices[idx] + solve( prices , idx +1 , 0 , fee , n , dp) , 0 + solve(prices , idx +1 , 1 , fee , n , dp)) ;
        }


        return dp[idx][buy] = max(prices[idx]- fee + solve(prices , idx +1 , 1 , fee , n , dp) , 0 + solve(prices , idx + 1 , 0 , fee , n , dp)) ;
     }

    int maxProfit(vector<int>& prices, int fee) {
        int n  = prices.size() ;

        vector<vector<int>>dp(n , vector<int>(2 , -1)) ;

        return solve(prices , 0 , 1 , fee ,n , dp) ;
        
    }
};