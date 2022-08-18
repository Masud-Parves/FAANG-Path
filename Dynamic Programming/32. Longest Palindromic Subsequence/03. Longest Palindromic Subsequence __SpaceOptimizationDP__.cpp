/*
    Problems Link : https://leetcode.com/problems/longest-palindromic-subsequence/
    TC - O(n*m)
    SC - O(m)

	Recurrence will be : 

	LCS(idx1, idx2) 
	text1[idx1] == text2[idx2] than 1 + LCS(idx1+1, idx2+1) 
	or LCS(idx1+1, idx2) max of LCS(idx1, idx2+1);
*/

class Solution {
private:
    int getLCS(string& s1, string& s2){
        int n = s1.size(), m = s2.size();
        vector<int> previousRow(m+1, 0);
        vector<int> currentRow(m+1, 0);
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s1[i-1] == s2[j-1]){
                    currentRow[j] = 1 + previousRow[j-1];
                } else {
                    currentRow[j] = max(previousRow[j], currentRow[j-1]);
                }
            }
            previousRow = currentRow;
        }
        return previousRow[m];
    }
public:
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s.begin(), s.end());
        return getLCS(s, s2);
    }
};