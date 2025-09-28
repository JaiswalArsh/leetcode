class Solution {
public:
    string toLowerCase(string s) {
        string ans;
        for (char ch : s) {
            int ascii_value = static_cast<int>(ch);
            if (ascii_value >= 65 && ascii_value <= 90)
                ascii_value += 32;
            ans.push_back((char)ascii_value);
        }
        return ans;
    }
};