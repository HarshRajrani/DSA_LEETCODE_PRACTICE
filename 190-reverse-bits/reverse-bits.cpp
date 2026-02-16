class Solution {
public:
    int reverseBits(int n) {
        if (n == 0) {
            return 0;
        }
        int result = 0 ;
        for (int i = 1; i <= 32; i++) {
            // shift to left  jagah banane k liye
            result <<= 1;

            //  then update or last bit nikalne ka liye

            result = (result | (n & 1));

            //  now right shift to find another last bit

            n >>= 1 ;
        }
        return result;
    }
};