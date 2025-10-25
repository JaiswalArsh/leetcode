class Solution {
public:
    int totalMoney(int n) {
        if (n == 1)
            return 1;
        int ans = 0;
        int s = 1;
        for (int i = 0; i < n; i++) {
            ans += s + (i % 7);
            if ((i + 1) % 7 == 0)
                s++;
        }
        return ans;
    }
};