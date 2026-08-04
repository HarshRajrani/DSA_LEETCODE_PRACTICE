class Solution {
public:
    int n;
    int solve(vector<vector<int>>& triangle, int i, int j,
              vector<vector<int>>& dp) {

        // base case 

        if (i == n - 1)
            return triangle[i][j];
        

        if (dp[i][j] != INT_MAX)
            return dp[i][j];

        int sum = triangle[i][j] + min(solve(triangle, i + 1, j, dp),
                                       solve(triangle, i + 1, j + 1, dp));

        return dp[i][j] = sum;
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        return solve(triangle, 0, 0, dp);
    }
};