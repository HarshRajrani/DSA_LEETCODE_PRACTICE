class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        int n = num.size();

        for (int i = 0; i < n; i++) {
            while (!st.empty() && k > 0 && num[i] < st.top()) {
                st.pop();

                k--;
            }

            st.push(num[i]);
        }

        while (k > 0 && !st.empty()) {
            k--;
            st.pop();
        }

        string ans = "";

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        int i = 0;

        while (i < ans.size() && ans[i] == '0') {
            i++;
        }

        ans = ans.substr(i);

        if (ans == "")
            return "0";

        return ans;
    }
};