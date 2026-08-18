class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        int n = nums.size();

        // k == 1
        if (k == 1) {
            unordered_map<int, int> mp;

            for (int x : nums) {
                mp[x]++;
            }

            int ans = -1;

            for (auto& it : mp) {
                if (it.second == 1) {
                    ans = max(ans, it.first);
                }
            }

            return ans;
        }

        // k == n
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        int count_start = 0;
        int count_end = 0;

        for (int i = 0; i < n; i++) {

            if (nums[0] == nums[i])
                count_start++;

            if (nums[n - 1] == nums[i])
                count_end++;
        }

        bool start = (count_start == 1);
        bool end = (count_end == 1);

        if (start && end)
            return max(nums[0], nums[n - 1]);

        if (start)
            return nums[0];

        if (end)
            return nums[n - 1];

        return -1;
    }
};