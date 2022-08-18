/*
    Problems Link : print LCS
    TC - O(n*m)
    SC - O(n*m)

	Recurrence will be : 

	LCS(idx1, idx2) 
	text1[idx1] == text2[idx2] than 1 + LCS(idx1+1, idx2+1) 
	or LCS(idx1+1, idx2) max of LCS(idx1, idx2+1);

*/

class Solution {
public:
    string printLongestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>>DP(n+1, vector<int>(m+1, 0));
        for(int idx1 = 1; idx1<=n ; idx1++){
            for(int idx2 = 1; idx2<=m ; idx2++){
                if(text1[idx1-1] == text2[idx2-1]){ // shifing index for base case;
                    DP[idx1][idx2] = 1 + DP[idx1-1][idx2-1];
                } else {
                    DP[idx1][idx2] = max(DP[idx1-1][idx2], DP[idx1][idx2-1]);
                }
            }
        }

        int len = DP[n][m];
        string ans(len, '#');

        int i=n, j=m;
        int idx = len-1;
        while(i>0 && j>0){
        	if(text1[i-1] == text2[j-1]){
                ans[idx--] = text1[i-1];
                i--;
                j--;
            } else {
            	if(DP[i-1][j]> DP[i][j-1]) i--;
            	else j--;
            }
        }
        return ans;
    }
};