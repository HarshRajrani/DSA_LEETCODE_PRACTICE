
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;

        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        // L[k] = all sums using k elements from left
        // R[k] = all sums using k elements from right
        vector<vector<int>> L(n + 1), R(n + 1);

        // Generate all subset sums
        for (int mask = 0; mask < (1 << n); mask++) {
            int cnt = 0, sumL = 0, sumR = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    cnt++;
                    sumL += left[i];
                    sumR += right[i];
                }
            }

            L[cnt].push_back(sumL);
            R[cnt].push_back(sumR);
        }

        // Sort right side for binary search
        for (int i = 0; i <= n; i++) {
            sort(R[i].begin(), R[i].end());
        }

        int total = accumulate(nums.begin(), nums.end(), 0);
        int ans = INT_MAX;

        // Try all splits
        for (int k = 0; k <= n; k++) {
            for (int a : L[k]) {

                // target we want from right side
                int target = total / 2 - a;

                auto& vec = R[n - k];

                // binary search
                auto it = lower_bound(vec.begin(), vec.end(), target);

                if (it != vec.end()) {
                    int sum = a + *it;
                    ans = min(ans, abs(total - 2 * sum));
                }

                if (it != vec.begin()) {
                    --it;
                    int sum = a + *it;
                    ans = min(ans, abs(total - 2 * sum));
                }
            }
        }

        return ans;
    }
};