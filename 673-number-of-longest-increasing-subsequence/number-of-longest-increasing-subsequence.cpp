class Solution {
public:

    // first  = LIS length
    // second = number of ways
    pair<int,int> solve(vector<int>& nums, int i, int j, int n,
                        vector<vector<pair<int,int>>>& dp) {

        // Base case
        if(i == n)
            return {0, 1};

        // Already calculated
        if(dp[i][j + 1].first != -1)
            return dp[i][j + 1];


        
        // NOT TAKEN
        
        pair<int,int> not_taken =
            solve(nums, i + 1, j, n, dp);


        
        // TAKEN
        
        pair<int,int> taken = {0, 0};

        if(j == -1 || nums[i] > nums[j]) {

            pair<int,int> temp =
                solve(nums, i + 1, i, n, dp);

            taken.first = 1 + temp.first;
            taken.second = temp.second;
        }


        
        // Compare
        

        pair<int,int> ans;

        // Taken gives longer LIS
        if(taken.first > not_taken.first) {

            ans = taken;
        }

        // Not taken gives longer LIS
        else if(not_taken.first > taken.first) {

            ans = not_taken;
        }

        // Both give same length
        else {

            ans.first = taken.first;

            ans.second =
                taken.second + not_taken.second;
        }


        return dp[i][j + 1] = ans;
    }


    int findNumberOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<vector<pair<int,int>>> dp(
            n,
            vector<pair<int,int>>(n + 1, {-1, -1})
        );

        pair<int,int> ans =
            solve(nums, 0, -1, n, dp);

        return ans.second;
    }
};