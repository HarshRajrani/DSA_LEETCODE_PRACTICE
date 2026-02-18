class Solution {
public:
    bool hasAlternatingBits(int n) {
        string binary = "";
        
        // integer n ko bit ka form ma likha rha hai 
        while (n > 0) {
            binary = char((n % 2) + '0') + binary;
            n /= 2;
        }
        
        for (int i = 0; i < binary.size() - 1; ++i) {
            if (binary[i] == binary[i + 1]) {
                return false;
            }
        }
        return true;
    }
};