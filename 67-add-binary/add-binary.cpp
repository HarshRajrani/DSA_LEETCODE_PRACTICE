class Solution {
public:
//
    string addBinary(string a, string b) {
        int n = a.length() - 1 ; 
        int m = b.length() - 1 ; 
        string result= "" ; 

        int carry = 0 ; int sum = 0 ; 

        while(m>=0 || n>=0 ){

            sum = carry ; 
            if( m >= 0){
                sum += b[m] - '0'  ;
                m-- ;
            }


             if(n >= 0){
                sum += a[n] - '0'  ;
                n-- ;
            }

            result.push_back((sum % 2 == 0) ? '0' : '1') ; 

            carry = (sum > 1) ? 1 : 0 ;
        }

        if(carry){
            result.push_back('1') ; 
        }

        reverse(result.begin()  , result.end()) ; 

        return result ; 
    }
};