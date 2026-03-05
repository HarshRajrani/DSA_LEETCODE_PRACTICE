class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int count1 = 0;
        int count2 = 0; 
        for (int i = 0; i < n; ++i) {
            char expected1 = (i % 2 == 0) ? '0' : '1'; // Pattern: 0101...
            char expected2 = (i % 2 == 0) ? '1' : '0'; // Pattern: 1010...
            if (s[i] != expected1) count1++;
            if (s[i] != expected2) count2++;
        }
        return min(count1, count2);
    }
};