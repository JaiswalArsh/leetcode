class Solution {
public:
    int maxDepth(string s) {
        int p=0;
        int ans=0;
        for(auto it:s){
            if(it=='(') p++;
            if(it==')') p--;
            ans=max(ans,p);
        }
        return ans;
    }
};