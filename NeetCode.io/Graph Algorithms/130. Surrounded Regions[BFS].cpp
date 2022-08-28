class Solution {
private:
    int fx[4] = {1, -1, 0, 0};
    int fy[4] = {0, 0, -1, 1};
    bool isValid(int r, int c, int row, int col){
        return (r>=0 && r<row && c>=0 && c<col);
    }
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size(), col = board[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));

        queue<pair<int, int>> Q;
        for(int r=0; r<row; r++){
            for(int c=0; c<col ; c++){
                if((r==0 || c==0 || r==row-1 || c==col-1) && board[r][c] == 'O'){
                    Q.push({r, c});
                    visited[r][c] = true;
                }
            }
        }
        
        while(!Q.empty()){
            int ux = Q.front().first;
            int uy = Q.front().second;
            Q.pop();
            for(int i=0; i<4; i++){
                int vx = ux + fx[i];
                int vy = uy + fy[i];
                if(isValid(vx, vy, row, col) == false) continue;
                if(board[vx][vy] == 'O' && visited[vx][vy] == false){
                    visited[vx][vy] = true;
                    Q.push({vx, vy});
                }
            }
        }
        
        for(int r=0; r<row; r++){
            for(int c=0; c<col; c++){
                if(board[r][c] == 'O' && visited[r][c] != true){
                    board[r][c] = 'X';
                }
            }
        }
        
        return;
    }
};