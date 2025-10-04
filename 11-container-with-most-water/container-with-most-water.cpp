class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        int l=0,r=height.size()-1;
        while(l<r){
            int ar=0;
            if(height[l]<height[r]){
                ar=height[l]*(r-l);
                l++;
            }
            else{
                ar=height[r]*(r-l);
                r--;
            }
            ans=max(ans,ar);
        }
        return ans;
    }
};