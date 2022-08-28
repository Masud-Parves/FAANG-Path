class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {        
		int freshOranges = 0;
	    queue<pair<int, int>> q;
	        
	    for(int i = 0; i < grid.size(); i++) {
			for(int j = 0; j < grid[0].size(); j++) {
				if(grid[i][j] == 1)
					freshOranges++;
	            else if(grid[i][j] == 2)
					q.push({i, j});
	        }
	    }

	    if(freshOranges == 0) return 0;
		int dx[] = {0, 0, 1, -1};
	    int dy[] = {1, -1, 0, 0};
	    int time = -1;
	    while(!q.empty()) {
			int n = q.size();
	        time++;
	        while(n--) {
				int x = q.front().first, y = q.front().second;
	            q.pop();
	            for(int i = 0; i < 4; ++i) {
					int nx = x + dx[i], ny = y + dy[i];
	                if(nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == 1) {
						grid[nx][ny] = 2;
	                    q.push({nx, ny});
	                    freshOranges--;
	                }
	            }
	        }
	    }  
	    return freshOranges == 0 ? time : -1;
	}
};