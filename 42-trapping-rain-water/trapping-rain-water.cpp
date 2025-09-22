
class Solution {
public:
    int trap(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] > arr[st.top()]) {
                int bottom = st.top();
                st.pop();
                if (st.empty())
                    break;
                int l = st.top();
                int r = i;
                int w = r - l - 1;
                int h = min(arr[l], arr[r]) - arr[bottom];
                ans += w * h;
            }
            st.push(i);
        }
        return ans;
    }
};