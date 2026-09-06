class Solution {
public:

    int longestStrChain(vector<string>& words) {

        int n = words.size();

        // Sort according to string length
        sort(words.begin(), words.end(), compare);

        // dp[i] = longest chain ending at words[i]
        vector<int> dp(n, 1);

        int maxLen = 1;

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < i; j++) {

                // Can words[j] be predecessor of words[i]?
                if(checkPossible(words[i], words[j]) &&
                   dp[i] < dp[j] + 1) {

                    dp[i] = dp[j] + 1;
                }
            }

            maxLen = max(maxLen, dp[i]);
        }

        return maxLen;
    }


    bool checkPossible(string& s, string& t) {

        // s should be exactly one character longer than t
        if(s.size() != t.size() + 1)
            return false;

        int i = 0;
        int j = 0;

        while(i < s.size()) {

            if(j < t.size() && s[i] == t[j]) {
                i++;
                j++;
            }
            else {
                // Skip extra character of s
                i++;
            }
        }

        return j == t.size();
    }


    static bool compare(string& a, string& b) {
        return a.size() < b.size();
    }
};