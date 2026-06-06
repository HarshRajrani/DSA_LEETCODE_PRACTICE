class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n, 0), suffixSum(n, 0), result(n, 0);

        
        for (int i = 1; i < n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }

        
        for (int i = n - 2; i >= 0; --i) {
            suffixSum[i] = suffixSum[i + 1] + nums[i + 1];
        }

        
        for (int i = 0; i < n; ++i) {
            result[i] = abs(prefixSum[i] - suffixSum[i]);
        }

        return result;
    }
};