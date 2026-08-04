class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        vector<int> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] + 1 != nums[i+1]) {
                
                
                int start = nums[i] + 1;
                int end = nums[i+1] - 1;

                for (int x = start; x <= end; x++) {
                    res.push_back(x);
                }
            }
        }
        return res;
    }
};