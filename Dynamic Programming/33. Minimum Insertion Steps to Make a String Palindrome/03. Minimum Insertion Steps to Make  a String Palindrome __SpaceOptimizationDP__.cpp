/*
    Problems Link : https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
    TC - O(n*m)
    SC - O(m)
	Recurrence will be : 

	LCS(idx1, idx2) 
	text1[idx1] == text2[idx2] than 1 + LCS(idx1+1, idx2+1) 
	or LCS(idx1+1, idx2) max of LCS(idx1, idx2+1);
*/

class Solution {
private:
	int LPS(string& s1, string& s2){
        int n = s1.size();
        vector<int> previousRow(n+1, 0);
        vector<int> currentRow(n+1, 0);
        
        for(int i = 1; i<=n ; i++){
            for(int j = 1; j<=n ; j++){
                if(s1[i-1] == s2[j-1]){
                    currentRow[j] = 1 + previousRow[j-1];
                } else {
                    currentRow[j] = max(previousRow[j], currentRow[j-1]);
                }
            }
            previousRow = currentRow;
        }
        return previousRow[n];
    }
public:
    int minInsertions(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        return s.size() - LPS(s, t);
    }
};