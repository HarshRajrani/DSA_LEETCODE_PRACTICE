class Solution {
public:
    bool solve(string& s, int i, int j, string& p, vector<vector<int>>& dp) {

        // base case

        if (i < 0 && j < 0)
            return true;

        if (i >= 0 && j < 0)
            return false;

        if (i < 0 && j >= 0) {

            for (int k = 0; k <= j; k++) {

                if (p[k] != '*')
                    return false;
            }

            return true;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        // same character or '?'

        if (s[i] == p[j] || p[j] == '?') {

            return dp[i][j] = solve(s, i - 1, j - 1, p, dp);
        }

        // '*'

        if (p[j] == '*') {

            return dp[i][j] =
                       (solve(s, i - 1, j, p, dp) || solve(s, i, j - 1, p, dp));
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {

        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(s, n - 1, m - 1, p, dp);
    }
};