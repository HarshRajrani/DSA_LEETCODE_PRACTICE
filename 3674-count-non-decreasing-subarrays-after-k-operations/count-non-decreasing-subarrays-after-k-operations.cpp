
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        long long ans = 0;
        long long cost = 0;
        int right = n - 1;
        deque<pair<int, int>> dq;
        for (int left = n - 1; left >= 0; left--) {
            int cnt = 1;

            while (!dq.empty() && dq.back().first < nums[left]) {
                cost += 1LL * (nums[left] - dq.back().first) * dq.back().second;
                cnt += dq.back().second;
                dq.pop_back();
            }
            dq.push_back({nums[left], cnt});
            while (cost > k) {
                cost -= dq.front().first - nums[right];

                if (dq.front().second == 1) {
                    dq.pop_front();
                }
                else {
                    dq.front().second--;
                }
                right--;
            }
            ans += right - left + 1;
        }
        return ans;
    }
};