class Solution {
private:
    void getParenthesis(int open, int close, int limit, string str, vector<string>& result, vector<vector<int>>& DP){
        if(open == limit && close == limit){
            result.push_back(str);
            return;
        }
        
        int& cache = DP[open][close];
        if(cache )
        
        if(open < limit) {
            getParenthesis(open+1, close, limit, str+'(', result);
        }
        
        if(close<open) {
            getParenthesis(open, close+1, limit, str+')', result);
        }
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        string str = "";
        vector<string> result;
        vector<vector<int>> DP(n, vector<int>(n, -1));
        getParenthesis(0, 0, n,str, result, DP);
        return result;
    }
};