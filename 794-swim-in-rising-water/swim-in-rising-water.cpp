class Solution {
public:
    int n;
    // 4 possible moves: up, down, left, right
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    
    // Check if we can reach (n-1, n-1) when water level = t
    bool canReach(vector<vector<int>>& grid, int t) {
        // If starting cell is higher than t, we can't even begin
        if (grid[0][0] > t) return false; 
        
        vector<vector<int>> vis(n, vector<int>(n, 0));
        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0] = 1;
        
        // BFS to explore reachable cells
        while (!q.empty()) {
            auto [x,y] = q.front(); q.pop();
            
            // If we reached bottom-right, path exists
            if (x == n-1 && y == n-1) return true;
            
            // Explore neighbors
            for (auto &d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                
                // Stay inside grid and only visit unvisited cells
                // whose elevation is <= current water level t
                if (nx>=0 && nx<n && ny>=0 && ny<n 
                    && !vis[nx][ny] && grid[nx][ny] <= t) {
                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }
        }
        return false; // no path found
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        
        int maxT = n*n;  // maximum possible elevation in grid is n^2 - 1
        
        // Brute-force: try every possible time t from 0 to n^2 - 1
        for (int t = 0; t < maxT; t++) {
            if (canReach(grid, t)) return t; // first time we can reach
        }
        return -1; // should never happen (problem guarantees a solution)
    }
};
