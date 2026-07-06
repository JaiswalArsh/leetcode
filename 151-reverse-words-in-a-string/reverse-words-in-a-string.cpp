#include <bits/stdc++.h>
class Solution {
public:
    vector<string> split(const string& s, char delimiter) {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, delimiter)) {
            if (!token.empty())
                tokens.push_back(token);
        }
        return tokens;
    }
    string reverseWords(string s) {
        string ans;
        vector<string> data = split(s, ' ');
        reverse(data.begin(), data.end());
        for (int i = 0; i < data.size(); i++) {
            ans += data[i];
            if (i != data.size() - 1)
                ans += ' ';
        }
        return ans;
    }
};