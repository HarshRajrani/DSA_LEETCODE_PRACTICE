class Solution {
public:
    int mirrorDistance(int n) {
        
        int a = n ;
        int rev = 0 ;
        while(n){
            rev = rev*10 + n%10 ;
            n/=10 ;


        }

        int ans = abs(a - rev) ;

        return ans ;
    }
};