class Solution {
public:

    	
	int solve(vector<int>& arr, int idx, int target, vector<vector<int>> &dp) {
		//  base case
		if (idx == 0) {
			if (target == 0 && arr[0] == 0)
				return 2;
			
			if (target == 0 || target == arr[0])
				return 1;
			
			return 0;
		}
		
		if (dp[idx][target] != -1)
			return dp[idx][target] ;
		
		int not_taken = solve(arr, idx - 1, target, dp) ;
		
		int taken = 0 ;
		
		if (arr[idx] <= target) {
			taken = solve(arr, idx - 1, target - arr[idx], dp) ;
		}
		
		return dp[idx][target] = taken + not_taken ;
		
	}
	int countPartitions(vector<int>& arr, int diff) {
		// Code here
		int n = arr.size() ;
		
		int totalsum = accumulate(arr.begin(), arr.end(), 0) ;
		
		if (abs(diff) > totalsum)
			return 0 ;
		
		if ((totalsum + diff) % 2 != 0)
			return 0 ;
		
		int target = (totalsum + diff)/2;
		vector<vector<int>> dp(n, vector<int>(target + 1, -1)) ;
		
		return solve(arr, n - 1, target, dp) ;
	}
    int findTargetSumWays(vector<int>& nums, int target) {
        
        return  countPartitions(nums , target) ;
    }
};