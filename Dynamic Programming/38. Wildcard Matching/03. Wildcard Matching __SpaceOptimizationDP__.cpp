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
        vector<bool>previousRow(m+1, false), currentRow(m+1, false);

        for(int i=1; i<m; i++){
            if(p[i-1] == '*') {
            	previousRow[i] = true;
            } else break;
        }
        previousRow[0] = true;
        currentRow[0] = true;
        for(int i=1; i<=n ; i++){
        	for(int j=1; j<=m; j++){
        		if(s[i-1] == p[j-1] || p[j-1] == '?') {
        			currentRow[j] = previousRow[j-1];
        		}else if(p[j-1] == '*') {
        			currentRow[j] = previousRow[j] | currentRow[j-1];
        		}
        	}
        	previousRow = currentRow;
        }

        return previousRow[m];
    }
};