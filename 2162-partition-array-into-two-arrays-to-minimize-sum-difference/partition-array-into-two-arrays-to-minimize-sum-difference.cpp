class Solution {
public:

    void generate(vector<int>& nums, int idx, int end,
                  int cnt, int sum,
                  vector<vector<int>>& v) {

        if (idx == end) {
            v[cnt].push_back(sum);
            return;
        }

        // Don't take
        generate(nums, idx + 1, end, cnt, sum, v);

        // Take
        generate(nums, idx + 1, end, cnt + 1, sum + nums[idx], v);
    }

    int minimumDifference(vector<int>& nums) {

        int n = nums.size();
        int total = 0;

        for (int x : nums)
            total += x;

        int half = n / 2;

        vector<vector<int>> left(half + 1);
        vector<vector<int>> right(half + 1);

        int mid = n / 2;

        generate(nums, 0, mid, 0, 0, left);
        generate(nums, mid, n, 0, 0, right);

        for (auto& v : right)
            sort(v.begin(), v.end());

        int ans = INT_MAX;

        // Take i elements from left
        // Then take half-i elements from right
        for (int i = 0; i <= half; i++) {

            int need = half - i;

            for (int x : left[i]) {

                // We want:
                // x + y ≈ total / 2
                //
                // y ≈ total/2 - x

                int target = total / 2 - x;

                auto& v = right[need];

                auto it = lower_bound(v.begin(), v.end(), target);

                if (it != v.end()) {
                    int selectedSum = x + *it;
                    ans = min(ans, abs(total - 2 * selectedSum));
                }

                if (it != v.begin()) {
                    --it;

                    int selectedSum = x + *it;
                    ans = min(ans, abs(total - 2 * selectedSum));
                }
            }
        }

        return ans;
    }
};