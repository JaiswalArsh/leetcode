class Solution {
public:
    void merge(vector<vector<int>>& a, int l, int m, int r) {
        vector<vector<int>> temp;
        int i = l, j = m + 1;
        while (i <= m && j <= r) {
            if (a[i][1] >= a[j][1]) temp.push_back(a[i++]);
            else temp.push_back(a[j++]);
        }
        while (i <= m) temp.push_back(a[i++]);
        while (j <= r) temp.push_back(a[j++]);
        for (int k = 0; k < temp.size(); k++) a[l + k] = temp[k];
    }
    void mergeSort(vector<vector<int>>& a, int l, int r) {
        if (l >= r) return;
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        mergeSort(boxTypes, 0, n - 1);
        int ans = 0;
        for (int i = 0; i < n && truckSize > 0; i++) {
            int boxes = min(truckSize, boxTypes[i][0]);
            ans += boxes * boxTypes[i][1];
            truckSize -= boxes;
        }
        return ans;
    }
};