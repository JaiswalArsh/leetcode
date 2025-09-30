class Solution {
public:
    vector<int> rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==0 || n<2) return nums;
        k= k%n;
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            temp[(i + k) % n] = nums[i];
        }
        nums = temp;
        return nums;
    }
};