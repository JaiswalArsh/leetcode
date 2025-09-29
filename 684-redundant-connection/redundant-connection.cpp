class Solution {
public:
    // DSU helpers
    int find(vector<int>& parent, int x) {
        if (parent[x] != x) 
            parent[x] = find(parent, parent[x]); // path compression
        return parent[x];
    }
    
    bool unite(vector<int>& parent, vector<int>& rank, int x, int y) {
        int px = find(parent, x), py = find(parent, y);
        if (px == py) return false; // already connected -> cycle
        
        if (rank[px] < rank[py]) swap(px, py);
        parent[py] = px;
        if (rank[px] == rank[py]) rank[px]++;
        return true;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1), rank(n+1, 0);
        for (int i = 1; i <= n; i++) parent[i] = i;
        
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            if (!unite(parent, rank, u, v)) {
                // this edge created a cycle
                return e;
            }
        }
        return {};
    }
};
