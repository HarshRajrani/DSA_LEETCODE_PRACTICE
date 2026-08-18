class Solution {
public:

    int solve(vector<int>& coins , int idx , int amount , vector<vector<int>> &dp){

        //  base case 
        if(amount == 0 ) return 1 ;

        if(idx == 0 ){
            if(amount % coins[0] == 0) return 1 ;

            return 0 ;
        }

        if(dp[idx][amount] != -1) return dp[idx][amount] ;
    

        //  recurrennce case 

        int not_taken = solve(coins , idx -1 , amount , dp ) ;

        int taken = 0 ;

        if(coins[idx] <= amount){
            taken = solve(coins , idx , amount - coins[idx] , dp) ;
        }

        return dp[idx][amount] = taken + not_taken ;
    }

    int change(int amount, vector<int>& coins) {
        

        int n = coins.size() ;

        vector<vector<int>> dp(n , vector<int>(amount+1 , -1)) ;

        return solve(coins , n-1 , amount , dp) ;

    }
};