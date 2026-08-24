class Solution {
public:
    int solve(string& s, string& t, int i, int j, vector<vector<int>>& dp) {

        // base case

        if (j < 0)
            return 1;

        if (i < 0)
            return 0;

        // already calculated

        if (dp[i][j] != -1)
            return dp[i][j];

        // recurrence case

        int taken = 0;
        int skip = 0;

        // characters same

        if (s[i] == t[j]) {

            taken = solve(s, t, i - 1, j - 1, dp);

            skip = solve(s, t, i - 1, j, dp);

            return dp[i][j] = taken + skip;
        }

        // characters different

        skip = solve(s, t, i - 1, j, dp);

        return dp[i][j] = skip;
    }

    int numDistinct(string s, string t) {

        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(s, t, n - 1, m - 1, dp);
    }
};