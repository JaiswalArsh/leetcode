class Solution {
public:
    int topologicalSort(vector<vector<int>>& edges, int v) {
        vector<vector<int>> adj(v);
        for (const auto& edge : edges)
            adj[edge[0]].push_back(edge[1]);
        vector<int> indegree(v, 0);
        for (int i = 0; i < v; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < v; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        int cnt = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
        return cnt;
    }
    bool canFinish(int v, vector<vector<int>>& edges) {
        return topologicalSort(edges, v) == v;
    }
};