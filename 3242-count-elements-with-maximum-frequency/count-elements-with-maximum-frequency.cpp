class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        int mf = 0;
        for (auto it : nums) {
            freq[it]++;
            mf = max(mf, freq[it]);
        }
        int ans = 0;
        for (auto& it : freq) {
            if (it.second == mf)
                ans += it.second;
        }
        return ans;
    }
};