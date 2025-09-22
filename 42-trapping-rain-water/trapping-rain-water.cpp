class Solution {
public:
    int trap(vector<int>& arr) {
        int ans = 0, LM = 0, RM = 0;
        int n = arr.size();
        int l = 0, r = n - 1;
        if (n == 0)
            return 0;
        stack<int> st;
        while (l < r) {
            if (arr[l] <= arr[r]) {
                if (LM > arr[l])
                    ans += LM - arr[l];
                else
                    LM = arr[l];
                l++;
            } else {
                if (RM > arr[r])
                    ans += RM - arr[r];
                else
                    RM = arr[r];
                r--;
            }
        }
        return ans;
    }
};