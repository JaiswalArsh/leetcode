class Solution {
public:
    int cnt(int n,vector<int> &dp) {
        if (n == 0)
            return 1;
        if (n == 1)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        dp[n] = cnt(n - 1, dp) + cnt(n - 2, dp);
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return cnt(n, dp);
    }
};