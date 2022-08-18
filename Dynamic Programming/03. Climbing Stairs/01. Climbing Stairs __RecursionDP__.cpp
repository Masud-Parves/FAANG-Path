/*
    Problems Link : https://leetcode.com/problems/climbing-stairs/
    TC - O(n)
    SC - O(n) + O(n)Resursion Stack Memory
*/

class Solution {
private:
    int helper(int idx, vector<int>& DP){
        if(idx == 0){
            return 1;
        }

        int& cache = DP[idx];
        if(cache != -1){
            return cache;
        }

        int way1 = 0, way2 = 0;
        way1 = helper(idx-1, DP);
        if(idx-2>=0){
            way2 = helper(idx-2, DP);
        } 
        return cache = way1 + way2;
    }
public:
    int climbStairs(int n) {
        vector<int> DP(n+1, -1);
        return helper(n, DP);
    }
};