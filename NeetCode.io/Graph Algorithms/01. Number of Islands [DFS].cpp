class Solution {
private:
    int fx[4]= {1,-1,0,0};
    int fy[4]= {0,0,1,-1};
    int row, col;
    void dfs(vector<vector<char>>& grid, int r, int c, vector<vector<bool>>& visited){
        if(r<0 or r>=row or c<0 or c>=col or grid[r][c] == '0' or visited[r][c] == true) return;
        
        visited[r][c] = true;
        
        for(int i=0; i<4; i++){
            dfs(grid, r + fx[i], c+fy[i], visited);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        row = grid.size(), col = grid[0].size();
        int islands = 0;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        for(int i=0; i<row; i++){
            for(int j=0; j<col ; j++){
                if(visited[i][j] == false && grid[i][j] == '1'){
                    islands++;
                    dfs(grid, i, j, visited);
                }
            }
        }
        return islands;
    }
};