/*
    Problems Link : https://leetcode.com/problems/longest-common-subsequence/
    TC - O(n*m)
    SC - O(n*m) + (n+m) Recursion Stack Memory

	Recurrence will be : 

	LCS(idx1, idx2) 
	text1[idx1] == text2[idx2] than 1 + LCS(idx1+1, idx2+1) 
	or LCS(idx1+1, idx2) max of LCS(idx1, idx2+1);

*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> DP(n, vector<int>(m, 0));

        for(int idx1=0; idx1<n; idx1++){
        	for(int idx2 = 0; idx2<m; idx2++){
        		int way1 = 0, way2 = 0;
        		if(text1[idx1] == text2[idx2]){
        			way1 = 1;
        			if(idx1-1>=0 && idx2-1>=0){
        				way1 += DP[idx1-1][idx2-1];
        			} 
        		} else {
        			if(idx1-1>=0) way2 = DP[idx1-1][idx2];
        			if(idx2-1>=0) way2 = max(way2, DP[idx1][idx2-1]);
        		}
                DP[idx1][idx2] = max(way1, way2);
        	}
        }
        return DP[n-1][m-1];
    }
};