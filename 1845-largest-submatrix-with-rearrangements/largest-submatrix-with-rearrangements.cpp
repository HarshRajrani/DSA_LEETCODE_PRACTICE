class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> prevRow(n, 0);
        int result = 0;

        for (int row = 0; row < m; row++) {
            vector<int> currRow = matrix[row];

            for (int col = 0; col < n; col++) {

                if (currRow[col] == 1) {
                    currRow[col] += prevRow[col];
                }
            }

            vector<int> sortedRow = currRow;
            sort(begin(sortedRow), end(sortedRow), greater<int>());

            for (int col = 0; col < n; col++) {
                int base = (col + 1);
                int height = sortedRow[col];

                result = max(result, base * height);
            }

            prevRow = currRow;
        }

        return result;
    }
};
