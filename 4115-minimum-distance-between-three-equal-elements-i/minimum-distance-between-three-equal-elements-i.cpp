class Solution {
public:
    int minimumDistance(vector<int>& b) {
       int n = b.size() ;
       int ans =INT_MAX;

       for(int i =0 ; i< n ; i++){
        for(int j = i+ 1  ; j< n ; j++){
            for(int k = j+1 ; k< n ; k++){

                if(b[i] == b[j]  && b[j]==b[k]){
                    ans = min(ans , 2*(k-i)) ;
                }
            }
        }
       }
        if(ans == INT_MAX) return -1 ;
        return ans ;
    }
};