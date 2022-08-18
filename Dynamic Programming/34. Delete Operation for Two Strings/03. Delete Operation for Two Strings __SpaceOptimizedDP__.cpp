/*
    Problems Link : https://leetcode.com/problems/delete-operation-for-two-strings/
    TC - O(n*m)
    SC - O(m)
	Recurrence will be : 

	LCS(idx1, idx2) 
	text1[idx1] == text2[idx2] than 1 + LCS(idx1+1, idx2+1) 
	or LCS(idx1+1, idx2) max of LCS(idx1, idx2+1);
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        vector<int>previousRow(m+1, 0), currentRow(m+1, 0);
        
        for(int i = 1; i<=n ; i++){
            for(int j=1; j<=m ; j++){
                if(word1[i-1] == word2[j-1]){
                    currentRow[j] = 1 + previousRow[j-1];
                } else {
                    currentRow[j] = max(previousRow[j], currentRow[j-1]);
                }
            }
            previousRow = currentRow;
        }
        
        int LCS = previousRow[m];
        
        int result = (n-LCS) + (m-LCS);
        return result;
    }
};