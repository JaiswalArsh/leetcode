class Solution {
public:
    void merge(vector<vector<int>>& a, int l, int m, int r) {
        vector<vector<int>> temp;
        int i = l, j = m + 1;
        while (i <= m && j <= r) {
            if (a[i][1] <= a[j][1]) temp.push_back(a[i++]);
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
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n <= 1) return 0;
        mergeSort(intervals, 0, n - 1);
        int remove = 0;
        int end = intervals[0][1];
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] < end) remove++;
            else end = intervals[i][1];
        }
        return remove;
    }
};