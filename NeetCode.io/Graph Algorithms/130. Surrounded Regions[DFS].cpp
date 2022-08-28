class Solution {
private:
    int fx[4] = {1, -1, 0, 0};
    int fy[4] = {0, 0, -1, 1};
    bool isValid(int r, int c, int row, int col){
        return (r>=0 && r<row && c>=0 && c<col);
    }
    
    void dfs(int ux, int uy, vector<vector<bool>>& visited, vector<vector<char>>& board){

        visited[ux][uy] = true;        
        for(int i=0; i<4; i++){
            int vx = fx[i] + ux;
            int vy = fy[i] + uy;
            if(isValid(vx, vy, board.size(), board[0].size())){
                //cout << vx << " " << vy << endl;
                if(board[vx][vy] == 'O' && visited[vx][vy]==false){
                    dfs(vx, vy, visited, board);
                }
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size(), col = board[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));

        for(int r=0; r<row; r++){
            for(int c=0; c<col ; c++){
                if((r==0 || c==0 || r==row-1 || c==col-1) && board[r][c] == 'O' && visited[r][c] == false){
                    //cout << r << " " << c << endl;
                    dfs(r, c, visited, board);
                }
            }
        }
        for(int r=0; r<row; r++){
            for(int c=0; c<col; c++){
                if(visited[r][c] != true){
                    board[r][c] = 'X';
                }
            }
        }
        return;
    }
};