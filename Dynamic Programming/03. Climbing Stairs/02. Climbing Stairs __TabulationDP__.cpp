/*
    Problems Link : https://leetcode.com/problems/climbing-stairs/
    TC - O(n)
    SC - O(n)
*/

class Solution {
public:
    int climbStairs(int n) {
        vector<int> DP(n+1, 0);
        DP[0] = 1;

        for(int i=1; i<=n; i++){
            DP[i] = DP[i-1];
            DP[i]+= (i-2>=0) ? DP[i-2] : 0;
        }
        return DP[n];
    }
};