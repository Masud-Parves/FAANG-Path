class Solution {
public:
    
    int row, col;
    int fx[4]= {1,-1,0,0};
    int fy[4]= {0,0,1,-1};
    bool isPossible(int r, int c){
        if(r<0 or r>=row or c<0 or c>= col) return false;
        return true;
    }
    
    void dfs(int sr, int sc, vector<vector<bool>>& visited, vector<vector<int>>& heights){
        if(!isPossible(sr, sc)) return;
            
        visited[sr][sc] = true;
        for(int i=0; i<4 ; i++){
            int vr = sr + fx[i];
            int vc = sc + fy[i];
            
            if(isPossible(vr, vc) && visited[vr][vc] == false){
                if(heights[sr][sc]<=heights[vr][vc]){
                    dfs(vr, vc, visited, heights);    
                }
            }
        }
        return;
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>points;
        row = heights.size(), col = heights[0].size();
        
        if(row == 0 && col == 0) return points;
        
        vector<vector<bool>>pacificVisited(row, vector<bool>(col));
        vector<vector<bool>>atlenticVisited(row, vector<bool>(col));
        
        for(int i=0; i<row ; i++){
            for(int k=0; k<col ; k++){
                pacificVisited[i][k] = false;
                atlenticVisited[i][k] = false;
            }
        }
        
        for(int i=0; i<row ; i++){
            dfs(i, 0, pacificVisited, heights);
            dfs(i, col-1, atlenticVisited, heights);
        }
        
        for(int i=0; i<col ; i++){
            dfs(0, i, pacificVisited, heights);
            dfs(row-1, i, atlenticVisited, heights);
        }
        
        for(int i=0; i<row ; i++){
            for(int k=0; k<col ; k++){
                if(pacificVisited[i][k] && atlenticVisited[i][k]) {
                    points.push_back({i, k});
                }
            }
        }
        return points;
    }
};