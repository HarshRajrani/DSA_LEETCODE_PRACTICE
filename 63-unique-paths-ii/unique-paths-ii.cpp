class Solution {
public:

    int n ,  m ;
    int solve(vector<vector<int>>& obstacleGrid , int i , int j , vector<vector<int>>&dp ){

        if( i >= n || j >=m || obstacleGrid[i][j] == 1) return 0 ; 

        if(i == n-1 && j == m-1) return 1 ;

        if(dp[i][j] != -1 ) return dp[i][j] ;

        return dp[i][j] = solve(obstacleGrid , i+1 , j , dp) + solve(obstacleGrid , i , j+1  , dp  ) ;

    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

         n  = obstacleGrid.size() ;
         m = obstacleGrid[0].size() ;
        vector<vector<int>>dp( n , vector<int>(m , -1)) ;

        return solve( obstacleGrid , 0 , 0 , dp) ;
    }
};