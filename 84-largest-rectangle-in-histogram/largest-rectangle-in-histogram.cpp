class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int ar = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int el = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                ar = max(ar, heights[el] * (nse - pse - 1));
            }
            st.push(i);
        }
        while (!st.empty()) {
            int el = st.top();
            st.pop();
            int nse = heights.size();
            int pse = st.empty() ? -1 : st.top();
            ar = max(ar, heights[el] * (nse - pse - 1));
        }
        return ar;
    }
};