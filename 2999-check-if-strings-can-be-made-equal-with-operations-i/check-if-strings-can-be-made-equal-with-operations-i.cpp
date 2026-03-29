class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int n = s2.size();
        if(s1 == s2) return true ;

        if (s1 != s2) {
            for (int i = 0; i < 2; i++) {
                if (s1[i] != s2[i]) {
                    swap(s2[i], s2[i + 2]);
                    if (s1 == s2) {
                        return true;
                        break;
                    }
                }
            }
        }

        return false;
    }
};