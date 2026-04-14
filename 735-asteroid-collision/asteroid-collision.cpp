class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int ast : asteroids) {
            bool destroyed = false;

            // top is moving RIGHT (+) and current is moving LEFT (-)
            while (!st.empty() && st.top() > 0 && ast < 0) {
                if (abs(st.top()) < abs(ast)) {
                    // Stack top is smaller, destroy it and keep checking
                    st.pop();
                    continue;
                }

                else if (abs(st.top()) == abs(ast)) {
                    // Both are equal, destroy both and stop
                    st.pop();
                    destroyed = true;
                    break;
                }

                else {
                    // Stack top is bigger, current asteroid is destroyed
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed) {
                st.push(ast);
            }
        }

        // Convert stack to vector
        int n = st.size();
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};