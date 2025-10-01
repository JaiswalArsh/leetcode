class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        while (numBottles >= numExchange) {
            int l = numBottles % numExchange;
            int ex = numBottles / numExchange;
            ans += ex;
            numBottles = l + ex;
        }
        return ans;
    }
};