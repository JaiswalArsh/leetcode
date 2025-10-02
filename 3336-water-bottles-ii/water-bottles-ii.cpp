class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = 0;
        int e = 0;
        while (numBottles > 0) {
            ans += numBottles;
            e += numBottles;
            numBottles = 0;
            if (e >= numExchange) {
                e -= numExchange;
                numBottles = 1;
                numExchange++;
            }
        }
        return ans;
    }
};