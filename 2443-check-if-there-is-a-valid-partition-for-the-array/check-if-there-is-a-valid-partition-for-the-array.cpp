class Solution {
public:
    bool solve(vector<int>& nums, int idx, vector<int>& dp) {

        //  base case

        if(idx == 0 ) return true ; 
        
        if(dp[idx] != -1) return dp[idx] ;

        //  recurrence case
        bool op1 = false;
        bool op2 = false;
        bool op3 = false;
        
        if( idx >=2 && nums[idx-1] == nums[idx-2]){
            op1 = solve(nums , idx-2 , dp) ;
        }

        if( idx >=3 && nums[idx-1] == nums[idx-2] && nums[idx -1] == nums[idx-3]){
            op2 = solve(nums , idx-3 , dp) ;
        }

        if( idx >=3 && nums[idx-3]+1 == nums[idx-2] && nums[idx-2] +1 == nums[idx-1]){
            op3 = solve(nums , idx-3 , dp) ;
        }

         return dp[idx] = (op1 || op2 || op3);
    }
    bool validPartition(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n+1, -1);

        return solve(nums, n , dp);
    }
};