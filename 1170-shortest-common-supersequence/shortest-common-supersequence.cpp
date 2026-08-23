class Solution {
public:
    int solve(string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {

        // base case

        if (i < 0)
            return j + 1;

        if (j < 0)
            return i + 1;

        // already calculated

        if (dp[i][j] != -1)
            return dp[i][j];

        // same character

        if (s1[i] == s2[j]) {

            return dp[i][j] = 1 + solve(s1, s2, i - 1, j - 1, dp);
        }

        // different character

        return dp[i][j] = 1 + min(solve(s1, s2, i - 1, j, dp),
                                  solve(s1, s2, i, j - 1, dp));
    }

    string shortestCommonSupersequence(string str1, string str2) {

        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        // calculate SCS length

        solve(str1, str2, n - 1, m - 1, dp);

        // printing SCS

        string ans = "";

        int i = n - 1;
        int j = m - 1;

        while (i >= 0 && j >= 0) {

            // same character

            if (str1[i] == str2[j]) {

                ans += str1[i];

                i--;
                j--;
            }

            // different character

            else {

                int op1 = solve(str1, str2, i - 1, j, dp);

                int op2 = solve(str1, str2, i, j - 1, dp);

                if (op1 <= op2) {

                    ans += str1[i];
                    i--;
                }

                else {

                    ans += str2[j];
                    j--;
                }
            }
        }

        // remaining characters

        while (i >= 0) {

            ans += str1[i];
            i--;
        }

        while (j >= 0) {

            ans += str2[j];
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};