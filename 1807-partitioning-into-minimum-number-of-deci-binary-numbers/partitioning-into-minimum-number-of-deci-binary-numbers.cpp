class Solution {
public:
    int minPartitions(string n) {
        int maxi = 0 ; 
        for(char c : n){
            int number = c - '0' ;

            if(number > maxi){
                maxi = number ; 
            }
        }
        return maxi ;
    }
};