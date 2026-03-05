class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int count1 = 0;
      //  int count2 = 0; 
        for (int i = 0; i < n; ++i) {
            char expected1 = (i % 2 == 0) ? '0' : '1'; // Pattern: 0101...
            if (s[i] != expected1) count1++;
           
        }
        return min(count1, n-count1);
    }
};