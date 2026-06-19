class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        int n = gain.size( ) ;

        int curr = 0 ;

        int highest = curr ;

        for(int i = 0 ; i< n ; i++){

            curr += gain[i] ;

            highest = max(highest , curr) ;
        }
        return highest ;
    }
};