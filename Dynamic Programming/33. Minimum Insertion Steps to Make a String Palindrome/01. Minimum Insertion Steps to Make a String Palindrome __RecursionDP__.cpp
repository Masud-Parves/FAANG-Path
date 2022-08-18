/*
    Problems Link : https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
    TC - O(n*m)
    SC - O(n*m) + (n+m) Recursion Stack Memory

	Recurrence will be : 

	LCS(idx1, idx2) 
	text1[idx1] == text2[idx2] than 1 + LCS(idx1+1, idx2+1) 
	or LCS(idx1+1, idx2) max of LCS(idx1, idx2+1);
*/

class Solution {
private:
	int calculateLCS(int id1, int id2, string& s1, string& s2, vector<vector<int>>& DP){
        if(id1< 0 || id2<0) return 0;

        int &ret = DP[id1][id2];
        if(ret != -1) return ret;
        
        if(s1[id1] == s2[id2]){
            return 1 + calculateLCS(id1-1, id2-1, s1, s2, DP);
        }
        
        return ret = max(calculateLCS(id1-1, id2, s1, s2, DP), calculateLCS(id1, id2-1, s1, s2, DP));
    }
    
    int getLCS(string& s1, string& s2){
        int n = s1.size(), m = s2.size();
        vector<vector<int>> DP (n, vector<int>(m, -1));
        return calculateLCS(n-1, m-1, s1, s2, DP);
    }
public:
    int minInsertions(string s) {
        string s2 = s;
        reverse(s.begin(), s.end());
        return s.size() - getLCS(s, s2);
    }
};