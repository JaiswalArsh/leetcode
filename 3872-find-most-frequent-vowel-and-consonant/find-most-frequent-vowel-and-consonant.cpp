class Solution {
public:
    int maxFreqSum(string s) {
        map<char, int> freq;
        string vowels = "aeiou";
        int v = 0;
        int c = 0;
        for (auto ch : s) {
            if (isalpha(ch))
                freq[ch]++;
        }
        for (const auto p : freq) {
            char ch = p.first;
            int cnt = p.second;
            if (vowels.find(ch) != string::npos)
                v = max(v, cnt);
            else
                c = max(c, cnt);
        }
        return c + v;
    }
};