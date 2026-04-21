class Solution {
public:
int dp[1001][1001];
   int solve(string &s , string &s2 , int i , int j ){

    // base case

    if(i < 0 || j<0) return 0 ;
    


    if(dp[i][j] != -1 ) return dp[i][j] ;
    //condition
    int take=0,skip=0;
    if(s[i]==s2[j]){
        take= 1 +solve(s,s2,i-1,j-1);
    }
    else{
        skip= max(solve(s,s2,i-1,j),solve(s,s2,i,j-1));
    }
    return dp[i][j]= max(skip,take);
   }


    int longestPalindromeSubseq(string s) {
        string s2 =s;
        reverse(s2.begin(),s2.end());
       
       memset(dp , -1 , sizeof(dp)) ;

       return solve(s, s2 , s.size()-1 , s2.size()-1);

    }
};