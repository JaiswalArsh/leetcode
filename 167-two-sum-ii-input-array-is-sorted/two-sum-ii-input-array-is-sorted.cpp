class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        int s = 0;
        while (l < r) {
            s = numbers[l] + numbers[r];
            if (s == target)
                return {l + 1, r + 1};
            if (s > target)
                r--;
            else
                l++;
        }
        return {-1,-1};
    }
};