class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1; // Special case for 0
        string binary = "";
        int temp = n;
        // Convert integer to binary string
        while (temp > 0) {
            binary = char((temp % 2) + '0') + binary;
            temp /= 2;
        }
        // Flip each bit in the binary string
        for (char &c : binary) {
            c = (c == '0') ? '1' : '0';
        }
        // Convert the flipped binary string back to integer
        int result = 0;
        for (char c : binary) {
            result = result * 2 + (c - '0');
        }
        return result;
    }
};