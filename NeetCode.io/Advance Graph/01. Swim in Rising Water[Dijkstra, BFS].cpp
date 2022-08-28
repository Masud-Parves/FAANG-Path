class Solution {
private:
    int fx[4] = {1, 0, -1, 0};
    int fy[4] = {0, 1, 0, -1};
    bool isValid(int r, int c, int row, int col){
        return (r>=0 && r<row && c>=0 && c<col);
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>>Q;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        Q.push({grid[0][0], {0, 0}});
        visited[0][0] = true;
        
        while(!Q.empty()){
            int ux = Q.top().second.first;
            int uy = Q.top().second.second;
            int weight = Q.top().first;
            Q.pop();
            if(ux == row-1 && uy == col-1){
                return weight;
            }
            for(int i=0; i<4; i++){
                int vx = ux + fx[i];
                int vy = uy + fy[i];
                
                if(isValid(vx, vy, row, col) && visited[vx][vy] == false){
                    visited[vx][vy] = true;
                    Q.push({max(weight, grid[vx][vy]), {vx, vy}});
                }
            }
        }
        return -1;
    }
};