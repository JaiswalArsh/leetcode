class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        long long ans = 0;
        int n = nums.size();
        unordered_map<int, int> freq;
        freq[0] = 1;
        int pr = 0;
        int ct = 0;
        for (int it : nums) {
            if (it == target)
                pr++;
            else
                pr--;
            for (auto& p : freq)
                if (p.first < pr)
                    ans += p.second;
            freq[pr]++;
        }
        return ans;
    }
};