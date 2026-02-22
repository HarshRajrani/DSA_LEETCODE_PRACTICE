class Solution {
public:
    int binaryGap(int n) {
        int prev = -1;         
        int maxGap = 0;       
      //  int index = 0; 

        for(int i = 0 ; i< 32 ; i++){
            if (n & 1) {     
                if (prev != -1) {
                    maxGap = max(maxGap, i - prev);
                }
                prev = i;
            }
            n >>= 1;         
           // ++index;
        }
        return maxGap;
    }
};