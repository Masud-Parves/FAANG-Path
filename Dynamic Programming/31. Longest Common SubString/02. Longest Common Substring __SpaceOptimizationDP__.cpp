/*
    Problems Link : https://www.codingninjas.com/codestudio/problems/longest-common-substring_1235207
    TC - O(n*m)
    SC - O(m) 
    Recurrence will be : 

    LCS(n, m) 
    text1[idx1] == text2[idx2] than 1 + LCS(idx1-1, idx2-1) 
    or LCS = 0;

*/

int lcs(string & s, string & t) {
    int n = s.size(), m = t.size();
    vector<int>previousRow(m+1, 0), currentRow(m+1, 0);
    
    int longest = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s[i-1] == t[j-1]){
                currentRow[j] = 1 + previousRow[j-1];
                if(longest<currentRow[j]){
                    longest = currentRow[j];
                }
            } else {
                currentRow[j] = 0;
            }
        }
        previousRow = currentRow;
    }
    
    return longest;
}