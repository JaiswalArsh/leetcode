class Solution {
public:
    bool checkDivisibility(int n) {
        int p = 1;
        int s = 0;
        int temp = n;
        while (temp > 0) {
            int t = temp % 10;
            temp = temp / 10;
            p *= t;
            s += t;
        }
        return (n % (p + s) == 0);
    }
};