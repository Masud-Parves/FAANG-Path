class Solution {
private:
	// Verdict : TLE

    int fx[4] = {1, -1, 0, 0};
    int fy[4] = {0, 0, -1, 1};
    bool isValid(int r, int c, int row, int col){
        return (r>=0 && r<row && c>=0 && c<col);
    }
    void backtracking(int r, int c, int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited, int& result, int currentMax){
        if(r == row-1 && c == col-1){
            currentMax = max(currentMax, grid[r][c]);
            result = min(result, currentMax);
            return;
        }
        visited[r][c] = true;
        currentMax = max(currentMax, grid[r][c]);
        for(int i=0; i<4; i++){
            int nr = r+fx[i];
            int nc = c+fy[i];
            if(isValid(nr, nc, row, col) && visited[nr][nc] == false){
                backtracking(nr, nc, row, col, grid, visited, result, currentMax);
            }
        }
        visited[r][c] = false;
        return;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        int result = INT_MAX;
        backtracking(0, 0, row, col, grid, visited, result, INT_MIN);
        return result;
    }
};