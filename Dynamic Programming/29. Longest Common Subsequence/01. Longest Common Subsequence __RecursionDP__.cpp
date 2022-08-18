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
private:
	int getLCS(int idx1, int idx2, string& text1, string& text2, vector<vector<int>>& DP){
		if(idx1==text1.size() || idx2==text2.size()){
			return 0;
		}

		int& cache = DP[idx1][idx2];
		if(cache != -1){
			return cache;
		}

		if(text1[idx1] == text2[idx2]){
			return cache = 1+getLCS(idx1+1, idx2+1, text1, text2, DP);
		}
		return cache = max(getLCS(idx1+1, idx2, text1, text2, DP), getLCS(idx1, idx2+1, text1, text2, DP));

	}
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> DP(n, vector<int>(m, -1));
        return getLCS(0, 0, text1, text2, DP);
    }
};