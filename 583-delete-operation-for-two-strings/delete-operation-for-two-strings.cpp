class Solution {
public:

int solve(string &word1, string &word2  , int i , int j ,vector<vector<int>> & dp){

    if( i < 0 || j < 0) return 0 ; 

    if(dp[i][j] != -1) return dp[i][j] ;

    //  recurrence case 

    int taken = 0 ; int not_taken = 0 ; 

    if(word1[i] == word2[j]){
        taken = 1 + solve(word1 , word2 , i-1 , j-1 , dp) ;
    }
    else{
        not_taken = max(solve (word1 , word2 , i-1 , j , dp) ,solve( word1 , word2 , i , j-1 , dp)) ;
    }

    return dp[i][j] = max(taken , not_taken ) ;
}

    int minDistance(string word1, string word2) {
        
        int n = word1.size() ; 
        int m = word2.size() ;

        vector<vector<int>>dp( n , vector<int>(m , -1)) ;

        int ans = n+ m - 2*solve(word1 , word2 ,  n -1 , m-1 , dp) ;

        return ans ;
    }
};