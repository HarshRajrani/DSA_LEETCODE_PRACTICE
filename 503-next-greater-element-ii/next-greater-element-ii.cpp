class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> result(n);

        stack<int> st;

        for (int i = 2 * n - 1; i >= 0; i--) {
            int idx = i % n;

            int curr = nums[idx];

            while (!st.empty() && st.top() <= curr) {
                st.pop();
            }

            if (i < n) {
                if (st.empty()) {
                    result[i] = -1;
                }

                else {
                    result[i] = st.top();
                }
            }

            st.push(curr);
        }
        return result;
    }
};