class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_area=0;
        int n = heights.size();
        stack<int>st;
        for ( int i=0; i<n;i++){
        while( !st.empty() && heights[st.top()]>=heights[i]){
            int idx = st.top();
            st.pop();
        
           int nse= i; // shuru mai
           int pse = st.empty()? -1: st.top();
           int width = nse-pse -1;
           int area = heights[idx] * width;
           max_area = max(area, max_area);

        }
        st.push(i);
        
        }
        while( !st.empty()){
            int idx = st.top();
            st.pop();
            int nse =n; // last mai
            int pse = st.empty() ?-1: st.top();
            int width = nse - pse-1;
            int area = heights[idx]  * width;
            max_area = max( area, max_area);
        }
        return max_area;
    }
};