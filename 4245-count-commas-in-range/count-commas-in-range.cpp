class Solution {
public:
    int countCommas(int n) {
        if (n <= 999)
            return 0;
        int ans = 0;
        int ms = 1000;
        while (n >= ms) {
            ans += (n - ms + 1);
            ms *= 1000;
        }
        return ans;
    }
};