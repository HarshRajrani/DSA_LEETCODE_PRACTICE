class Solution {
public:
    int solve(string& word1, string& word2, int i, int j,
              vector<vector<int>>& dp) {

        // base case

        if (i < 0)
            return j + 1;

        if (j < 0)
            return i + 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        // recurrence case
        int deletion = 0, insertion = 0, replaces = 0;

        if (word1[i] == word2[j]) {
            return dp[i][j] = solve(word1, word2, i - 1, j - 1, dp);
        }

        else {

            deletion = 1 + solve(word1, word2, i - 1, j, dp);
            insertion = 1 + solve(word1, word2, i, j - 1, dp);
            replaces = 1 + solve(word1, word2, i - 1, j - 1, dp);
        }
        return dp[i][j] = min(deletion, min(insertion, replaces));
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(word1, word2, n - 1, m - 1, dp);
    }
};