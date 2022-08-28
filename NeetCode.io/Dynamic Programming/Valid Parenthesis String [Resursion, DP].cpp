class Solution {
private:
    bool helper(int idx, string& s, int take, vector<vector<int>>& DP){
        if(take <0 || idx > s.size()){
            return 0;
        }
        if(idx == s.size() && take == 0){
            return 1;
        }
        
        int& cache = DP[idx][take];
        if(cache != -1){
            return cache;
        }
        
        if(s[idx] == '*'){
           cache = helper(idx+1, s, take, DP) | helper(idx+1, s, take+1, DP) | helper(idx+1, s, take-1, DP);
        }  else {
            if(s[idx] == '(')
                cache = helper(idx+1, s, take+1, DP);
            else cache = helper(idx+1, s, take-1, DP);
        }
        return cache;
    }
    
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> DP(n+1, vector<int>(n+1, -1));
        return helper(0, s, 0, DP);
    }
};