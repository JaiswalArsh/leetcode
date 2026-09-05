class Solution {
public:
    string minWindow(string s, string t) {
        int minl = INT_MAX;
        int st = -1, l = 0, r = 0, cnt = 0;
        int h[256] = {0};
        for (int j = 0; j < t.size(); j++)
            h[t[j]]++;
        while (r < s.size()) {
            if (h[s[r]] > 0)
                cnt++;
            h[s[r]]--;
            r++;
            while (cnt == t.size()) {
                if (r - l < minl) {
                    minl = r - l;
                    st = l;
                }
                h[s[l]]++;
                if (h[s[l]] > 0)
                    cnt--;
                l++;
            }
        }
        return (st == -1) ? "" : s.substr(st, minl);
    }
};