class Solution {
public:
    int dp[201][20001];

    bool solve(vector<int>& nums, int i, int x) {

        //   base case

        if (x == 0)
            return true;

        if (i >= nums.size())
            return false;

        if (dp[i][x] != -1)
            return dp[i][x];

        bool take = false;

        if (x >= nums[i]) {

            take = solve(nums, i + 1, x - nums[i]);
        }

        bool notTake = false;

        notTake = solve(nums, i + 1, x);

        return dp[i][x] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {

        int n = nums.size();

        int s = accumulate(nums.begin(), nums.end(), 0);

        if (s % 2)
            return false;

        int x = s / 2;

        memset(dp, -1, sizeof(dp));
        // vector<vector<int>> dp(n+1 ,  vector<int>(x+1 , -1)) ;

        return solve(nums, 0, x);
    }
};