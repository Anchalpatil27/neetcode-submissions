
class Solution {
public:
    bool isSafe(vector<vector<char>>& grid, int r, int c,
                vector<vector<bool>>& visited) {
        int n = grid.size();
        int m = grid[0].size();

        return (r >= 0 && r < n &&
                c >= 0 && c < m &&
                grid[r][c] == '1' &&
                !visited[r][c]);
    }

    void bfs(vector<vector<char>>& grid, int r, int c,
             vector<vector<bool>>& visited) {
        vector<int> dr = {1, -1, 0, 0};
        vector<int> dc = {0, 0, 1, -1};

        queue<pair<int, int>> q;
        q.push({r, c});
        visited[r][c] = true;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (isSafe(grid, nr, nc, visited)) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(
            n, vector<bool>(m, false)
        );

        int islands = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    bfs(grid, i, j, visited);
                    islands++;
                }
            }
        }

        return islands;
    }
};

