class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> hight(gain.size() + 1, 0);
        for (int i = 0; i < gain.size(); i++) {
            hight[i + 1] = hight[i] + gain[i];
        }
        return *max_element(hight.begin(), hight.end());
    }
};