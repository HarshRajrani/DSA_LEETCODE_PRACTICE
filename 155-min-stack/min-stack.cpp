class MinStack {
    private:
        // Use long long to prevent overflow during the 2*val - mini calculation
        stack<long long> st;
        long long mini;

    public:
        MinStack() {}

        void push(int val) {
            long long value = val;
            if (st.empty()) {
                st.push(value);
                mini = value;
            } else {
                if (value >= mini) {
                    st.push(value);
                } else {
                    // Encoding the new minimum
                    st.push(2 * value - mini);
                    mini = value;
                }
            }
        }

        void pop() {
            if (st.empty()) return;

            long long x = st.top();
            st.pop();

            // If x < mini, it means x was an encoded value
            // We must retrieve the previous minimum
            if (x < mini) {
                mini = 2 * mini - x;
            }
        }

        int top() {
            if (st.empty()) return -1;
            long long x = st.top();
            
            // If top is less than mini, mini IS the actual value
            if (x < mini) return (int)mini;
            return (int)x;
        }

        int getMin() {
            return (int)mini;
        }
};