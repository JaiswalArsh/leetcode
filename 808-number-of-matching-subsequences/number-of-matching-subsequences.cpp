class Solution {
public:
    unordered_map<char, vector<int>> buildMap(const string& s) {
        unordered_map<char, vector<int>> cf;
        for (int i = 0; i < s.length(); ++i)
            cf[s[i]].push_back(i);
        return cf;
    }
    bool isSubsequence(const string& s, const string& word,
                       const unordered_map<char, vector<int>>& cf) {
        int lastPosition = -1;
        for (char c : word) {
            if (cf.find(c) == cf.end())
                return false;
            const vector<int>& indices = cf.at(c);
            auto it = upper_bound(indices.begin(), indices.end(), lastPosition);
            if (it == indices.end())
                return false;
            lastPosition = *it;
        }
        return true;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, vector<int>> cf = buildMap(s);
        int count = 0;
        for (const string& word : words) {
            if (isSubsequence(s, word, cf))
                count++;
        }
        return count;
    }
};
