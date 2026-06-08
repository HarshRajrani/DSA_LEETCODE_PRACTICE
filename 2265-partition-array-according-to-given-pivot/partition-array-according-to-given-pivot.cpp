class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        list<int> arr ;
        list<int> equal ; 
        list<int> greater ; 

        for(auto num : nums){

            if(num < pivot){
                arr.push_back(num) ;
            }else if( num > pivot){
                greater.push_back(num) ;
            }else{
                equal.push_back(num) ;
            }
        }

        arr.insert(arr.end() , equal.begin() , equal.end()) ;
        arr.insert(arr.end(), greater.begin() , greater.end()) ;

        vector<int> ans ; 

        for(auto num : arr){
            ans.push_back(num) ;
        }

        return ans ;

    }
};