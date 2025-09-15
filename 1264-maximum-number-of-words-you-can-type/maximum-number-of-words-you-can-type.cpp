class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int i = 0;
        vector<string> word;
        int j = 1;
        for (j = 1; j < text.size(); j++) {
            if (text[j] == ' ') {
                word.push_back(text.substr(i, j - i));
                i = j + 1;
            }
        }
        word.push_back(text.substr(i, j - i));
        int cnt = 0;
        for (auto it : word) {
            bool broken = false;
            for (int k = 0; k < brokenLetters.size(); k++) {
                if (it.find(brokenLetters[k]) != string::npos) {
                    broken = true;
                    break;
                }
            }
            if (!broken) cnt++;
        }
        return cnt;
    }
};
