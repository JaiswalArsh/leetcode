class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n1 = a.size(), n2 = b.size();
        int i = 0, j = 0;
        int n = n1 + n2;
        int ind2 = n / 2, ind1 = ind2 - 1;
        int cnt = 0;
        int el1 = -1, el2 = -1;
        while (i < n1 && j < n2) {
            if (a[i] < b[j]) {
                if (cnt == ind1)
                    el1 = a[i];
                if (cnt == ind2)
                    el2 = a[i];
                cnt++;
                i++;
            } else {
                if (cnt == ind1)
                    el1 = b[j];
                if (cnt == ind2)
                    el2 = b[j];
                cnt++;
                j++;
            }
        }
        while (i < n1) {
            if (cnt == ind1)
                el1 = a[i];
            if (cnt == ind2)
                el2 = a[i];
            cnt++;
            i++;
        }
        while (j < n2) {
            if (cnt == ind1)
                el1 = b[j];
            if (cnt == ind2)
                el2 = b[j];
            cnt++;
            j++;
        }
        if (n % 2 == 1) {
            return (double)el2;
        }
        return (double)((double)el1 + (double)el2) / 2.0;
    }
};