#include<map>
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int> m;
        m[0]=1;
        int presum=0,c=0;
        for(int i=0;i<n;i++){
            presum+=nums[i];
            int r=presum-k;
            c+=m[r];
            m[presum]+=1;
        }
        return c;
    }
};