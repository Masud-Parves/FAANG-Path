/*
    Problems Link : https://leetcode.com/problems/wildcard-matching/
    TC - O(n*m)
    SC - O(n*m)
	Recurrence will be : 

	P[i][j] = P[i - 1][j - 1] && (s[i-1] == p[j-1] || p[j-1] == '?'), if p[j-1] != '*';
	P[i][j] = P[i][j - 1] || P[i - 1][j], if p[j-1] == '*'
*/

class Solution {
public:
bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> DP(n+1, vector<bool>(m+1, false));
		for (int j = 0; j < p.size() && p[j] == '*'; ++j) {
            DP[0][j + 1] = true;
        }

        DP[0][0] = true;
        for(int i=0; i< m; i++){
            if(p[i] == '*') {
            	DP[0][i+1] = true;
            } else break;
        }

        for(int i=1; i<=n ; i++){
        	for(int j=1; j<=m; j++){
        		if(s[i-1] == p[j-1] || p[j-1] == '?') {
        			DP[i][j] = DP[i-1][j-1];
        		}else if(p[j-1] == '*') {
        			DP[i][j] = DP[i-1][j] | DP[i][j-1];
        		}
        	}
        }

        return DP[n][m];
    }
};