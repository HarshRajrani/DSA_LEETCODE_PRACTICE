class Solution {
public:
    int subarraycount(vector<int> nums, int mid) {
        int n = nums.size();
        int subarray = 1;
        int totalsum = 0;

        for (int i = 0; i < n; i++) {

            if (totalsum + nums[i] <= mid) {
                totalsum += nums[i];
            } else {
                subarray++;
                totalsum = nums[i];
            }
        }
        return subarray;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end() , 0);

        while (low <= high) {
            int mid = (low + high) / 2;

            int subarray = subarraycount(nums, mid);

            if (subarray > k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};