class Solution {
public:
    int minPartitions(string n) {
        int maxi = 0 ; 
        for(char c : n){
            int number = c - '0' ;

           maxi = max(maxi , number ) ;
        }
        return maxi ;
    }
};