class Solution {
public:

    bool solve(vector<int>& nums, int idx, int target,
               vector<vector<int>>& dp) {

        if (target == 0)
            return true;

        if (idx == 0)
            return nums[0] == target;

        if (dp[idx][target] != -1)
            return dp[idx][target];

        bool not_take = solve(nums, idx - 1, target, dp);

        bool take = false;
        if (nums[idx] <= target)
            take = solve(nums, idx - 1, target - nums[idx], dp);

        return dp[idx][target] = take || not_take;
    }

    bool canPartition(vector<int>& nums) {

        int n = nums.size();

        int sum = 0;
        for (int x : nums)
            sum += x;

        if (sum % 2)
            return false;

        int target = sum / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return solve(nums, n - 1, target, dp);
    }
};