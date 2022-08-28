
class Solution {
private:
    int fx[4] = {0, 0, 1, -1};
    int fy[4] = {1, -1, 0, 0};
    void bfs(int r, int c, vector<vector<bool>>& visited, vector<vector<char>>& grid){
        int row = grid.size(), col = row ? grid[0].size() : 0;
        queue<pair<int, int>> Q;
        Q.push({r, c});
        visited[r][c] = true;
        
        while(!Q.empty()){
            auto uNode = Q.front();
            Q.pop();
            
            int ux = uNode.first;
            int uy = uNode.second;
            
            for(int i=0; i<4; i++){
                int vx = ux + fx[i];
                int vy = uy + fy[i];
                if(vx>=0 && vx<row && vy>=0 && vy<col && grid[vx][vy]=='1' && visited[vx][vy]==false){
                    Q.push({vx, vy});
                    visited[vx][vy] = true;
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size(), col = row ? grid[0].size() : 0;
        int islands = 0;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == '1' && visited[i][j] == false){
                    bfs(i, j, visited, grid);
                    islands++;
                }
            }
        }
        return islands;
    }
};