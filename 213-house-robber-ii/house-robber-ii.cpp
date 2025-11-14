class Solution {
public:
    int maximumNonAdjacentSum(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;
        for (int i = 1; i < n; i++) {
            int take = nums[i];
            if (i > 1)
                take += prev2;
            int nontake = 0 + prev;
            int curi = max(take, nontake);
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }
    int rob(vector<int>& houses) {
        vector<int> temp1, temp2;
        int n = houses.size();
        if (n == 1)
            return houses[0];
        for (int i = 0; i < n; i++) {
            if (i != 0)
                temp1.push_back(houses[i]);
            if (i != n - 1)
                temp2.push_back(houses[i]);
        }
        return max(maximumNonAdjacentSum(temp1), maximumNonAdjacentSum(temp2));
    }
};