class Solution {
public:
    long long sumAndMultiply(int n) {
        if (n == 0)
            return 0;
        string s = to_string(n);
        string ans = "";
        int cnt = 0;
        for (auto it : s) {
            if (it != '0') {
                ans += it;
                cnt += (it - '0');
            }
        }
        long long numeric_ans = ans.empty() ? 0 : std::stoll(ans);
        return cnt * numeric_ans;
    }
};