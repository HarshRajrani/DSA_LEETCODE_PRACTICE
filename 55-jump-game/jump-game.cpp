//  Greedy Approach 


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size() ;
        int maxelement = 0 ;

        for(int i = 0 ; i< n  ; i++){

            if( i > maxelement)  return false ;

            else{
                maxelement = max(maxelement , i + nums[i]) ;
            }
            
        }

        return true ;
    }
};