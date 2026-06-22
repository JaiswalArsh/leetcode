class Solution {
public:
    int maxIceCream(vector<int>& cost, int coins) {
        sort(cost.begin(),cost.end());
        int cnt=0;
        for(int i=0;i<cost.size();i++){
            if(coins==0) break;
            if(cost[i]<=coins){
                cnt++;
                coins-=cost[i];
            }
        }
        return cnt;
    }
};