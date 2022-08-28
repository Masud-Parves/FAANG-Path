class Solution {
public:
    int row, col;
    
    bool isPossible(int r, int c){
        if(r<0 or r>=row or c<0 or c>=col) return false;
        return true;
    }
    
    void bfs(queue<pair<int, int>>&Q, vector<vector<bool>>& visited, vector<vector<int>>& heights){
        
        int fx[4]= {1,-1,0,0};
        int fy[4]= {0,0,1,-1};
        
        while(!Q.empty()){
            int ux = Q.front().first;
            int uy = Q.front().second;
            Q.pop();
            
            for(int i=0; i<4; i++){
                int vx = ux + fx[i];
                int vy = uy + fy[i];
                
                if(isPossible(vx, vy) && visited[vx][vy] == false){
                    if(heights[ux][uy]<=heights[vx][vy]){
                        visited[vx][vy] = true;
                        Q.push({vx, vy});
                    }
                }
            }
        }
        return;
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        row = heights.size(), col = heights[0].size();
        vector<vector<int>>points;
        if(row == 0 && col == 0) return points;
        
        vector<vector<bool>> pacificVisited( row , vector<bool> (col));
        vector<vector<bool>> atlanticVisited( row , vector<bool> (col));
        
        for(int i=0; i<row ; i++){
            for(int j=0; j<col ; j++){
                pacificVisited[i][j] = false;
                atlanticVisited[i][j] = false;
            }
        }
        
        queue<pair<int, int>>pacificQueue;
        queue<pair<int, int>>atlanticQueue;
        
        for(int i=0; i<row ; i++){
            pacificQueue.push({i, 0});
            atlanticQueue.push({i, col-1});
            pacificVisited[i][0] = true;
            atlanticVisited[i][col-1] = true;
        }
        
        for(int i=0; i<col ; i++){
            pacificQueue.push({0, i});
            atlanticQueue.push({row-1, i});
            pacificVisited[0][i] = true;
            atlanticVisited[row-1][i] = true;
        }
        
        bfs(pacificQueue, pacificVisited, heights);
        bfs(atlanticQueue, atlanticVisited, heights);
        
        for(int i=0; i<row ; i++){
            for(int k=0; k<col ; k++){
                if(pacificVisited[i][k] && atlanticVisited[i][k]){
                    points.push_back({i, k});
                }
            }
        }
        return points;
    }
};