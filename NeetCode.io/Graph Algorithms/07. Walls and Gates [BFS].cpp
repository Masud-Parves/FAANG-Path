class Solution {
private:
    bool isValid(int r, int c, int row, int col){
        return (r>=0 && r<row && c>=0 && c<col);
    }
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int row = rooms.size(), col = rooms[0].size();
        vector<vector<int>> dis(row, vector<int>(col, INT_MAX-1000));
        
        queue<pair<int, int>> Q;
        for(int r = 0; r<row ; r++){
            for(int c=0; c<col ; c++){
                if(rooms[r][c] == 0){
                    Q.push({r, c});
                }
            }
        }
        
        int fx[4] = {1, -1, 0, 0};
        int fy[4] = {0, 0, -1, 1};
        
        while(!Q.empty()){
            int ux = Q.front().first;
            int uy = Q.front().second;
            Q.pop();
            
            for(int i=0; i<4; i++){
                int vx = ux + fx[i];
                int vy = uy + fy[i];
                if(isValid(vx, vy, row, col)){
                    if(rooms[vx][vy] > rooms[ux][uy] + 1){
                        rooms[vx][vy] = 1 + rooms[ux][uy];
                        Q.push({vx, vy});
                    }
                }
            }
        }
        return;
    }
};