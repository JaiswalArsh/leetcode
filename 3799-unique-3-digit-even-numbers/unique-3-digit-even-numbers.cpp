class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> pool(10, 0);
        int ans = 0;
        for (auto d : digits)
            pool[d]++;
        for (int i = 100; i < 1000; i += 2) {
            int d1 = i / 100;
            int d2 = (i / 10) % 10;
            int d3 = i % 10;
            vector<int> need(10, 0);
            need[d1]++;
            need[d2]++;
            need[d3]++;
            bool val = true;
            for (int i = 0; i < 10; i++) {
                if (pool[i] < need[i]) {
                    val = false;
                    break;
                }
            }
            if (val)
                ans++;
        }
        return ans;
    }
};