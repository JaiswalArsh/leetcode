class Solution {
public:
    int rearrangeCharacters(string s, string t) {
        vector<int> cntS(26, 0);
        vector<int> cntT(26, 0);
        for (auto it : s)
            cntS[it - 'a']++;
        for (auto it : t)
            cntT[it - 'a']++;
        int maxcopy = INT_MAX;
        for (int i = 0; i < 26; ++i) {
            if (cntT[i] > 0)
                maxcopy = min(maxcopy, cntS[i] / cntT[i]);
        }
        return maxcopy;
    }
};