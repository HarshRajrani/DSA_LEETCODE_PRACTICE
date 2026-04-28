class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {

        vector<int> nums;

        // flatten grid + check validity
        int rem = grid[0][0] % x;

        for (auto& row : grid) {
            for (int num : row) {

                // impossible case
                if (num % x != rem)
                    return -1;

                nums.push_back(num);
            }
        }

        sort(nums.begin(), nums.end());

        int n = nums.size();

        int target = nums[n / 2];

        int operations = 0;

        for (int num : nums) {
            operations += abs(num - target) / x;
        }

        return operations;
    }
};