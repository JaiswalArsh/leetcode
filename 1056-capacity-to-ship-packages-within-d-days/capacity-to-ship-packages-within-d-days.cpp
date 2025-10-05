class Solution {
public:
    int time(vector<int>& weight, int mid) {
        int days = 1, load = 0;
        for (int i = 0; i < weight.size(); i++) {
            if (load + weight[i] > mid) {
                days++;
                load = weight[i];
            } else
                load += weight[i];
        }
        return days;
    }
    int shipWithinDays(vector<int>& weight, int days) {
        int low = *max_element(weight.begin(),weight.end());
        int high =accumulate(weight.begin(),weight.end(),0);
        while (low <= high) {
            int mid = (low + high) / 2;
            if (time(weight, mid) <= days)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};