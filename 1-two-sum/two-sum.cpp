class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int s = nums.size();
        vector<int> a;
        for(int i=0;i<s;i++){
            for(int j=i+1;j<s;j++){
                if(nums[i]+nums[j]== target){
                    a.push_back(i);
                    a.push_back(j); 
                    return a;   
                }
            }
        }
        return a;
    }
};