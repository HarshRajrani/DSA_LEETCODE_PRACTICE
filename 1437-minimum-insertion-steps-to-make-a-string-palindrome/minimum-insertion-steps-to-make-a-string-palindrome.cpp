class Solution {
public:

    int solve(string& s, string& s2,
              int i, int j,
              vector<vector<int>>& dp) {

        // base case
        if(i < 0 || j < 0)
            return 0;

        // already calculated
        if(dp[i][j] != -1)
            return dp[i][j];

        int taken = 0;
        int not_taken = 0;

        // characters same
        if(s[i] == s2[j]) {

            taken = 1 + solve(
                s, s2,
                i - 1,
                j - 1,
                dp
            );
        }

        // characters different
        else {

            not_taken = max(
                solve(s, s2, i - 1, j, dp),
                solve(s, s2, i, j - 1, dp)
            );
        }

        return dp[i][j] = max(taken, not_taken);
    }


    int longestPalindromeSubseq(string s) {

        int n = s.size();

        string s2 = s;

        reverse(s2.begin(), s2.end());

        int m = s2.size();

        vector<vector<int>> dp(
            n,
            vector<int>(m, -1)
        );

        return solve(
            s, s2,
            n - 1,
            m - 1,
            dp
        );
    }


    int minInsertions(string s) {

        int n = s.size();

        int answer =
            n - longestPalindromeSubseq(s);

        return answer;
    }
};