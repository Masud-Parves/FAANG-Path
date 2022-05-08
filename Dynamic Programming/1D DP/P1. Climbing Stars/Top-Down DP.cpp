class Solution {
public:
    int climbStairs(int n) {
        vector<int>DP(n, -1);
        int ret = solve(0, n, DP);
        return ret;
    }
    
    int solve(int pos, int n, vector<int>& DP){
        if(pos>n) return 0;
        if(n == pos) return 1;
        
        int &ret = DP[pos];
        if(ret != -1) return ret;
        ret = 0;
        
        ret += solve(pos+1, n, DP);
        ret += solve(pos+2, n, DP);
        return ret;
    }
};