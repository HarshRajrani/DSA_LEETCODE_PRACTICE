class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size() ; 

        vector<int> result(n , -1) ;

        for(int i = 0 ; i < n ; i++){

            int curr = nums[i] ;

            for(int j = 1 ; j < n ; j++){

                int idx = (j+i) % n ; 

                if(nums[idx] > curr){

                    result[i] =  nums[idx] ;

                    break ; 
                }
            }
        }

        return result ; 
     }
};