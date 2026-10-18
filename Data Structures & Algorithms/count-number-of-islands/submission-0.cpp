class Solution {
public:
bool isSafe(vector<vector<char>>&grid,int r,int c,vector<vector<bool>>&visited){
    int n = grid.size();
    int m = grid[0].size();
    return (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == '1' && !visited[r][c]);
}
void dfs(vector<vector<char>>&grid,int r,int c,vector<vector<bool>>&visited){
    visited[r][c] = true;
    vector<int>dr = {1,-1,0,0};
    vector<int>dc = {0,0,1,-1};
    for(int k =0;k<4;k++){
        int nr = r + dr[k];
        int nc = c + dc[k];

        if(isSafe(grid,nr,nc,visited))
         dfs(grid,nr,nc,visited);
    }
}
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int islands = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    dfs(grid,i,j,visited);
                    islands++;
                }
            }
        }
        return islands;

    }
};
