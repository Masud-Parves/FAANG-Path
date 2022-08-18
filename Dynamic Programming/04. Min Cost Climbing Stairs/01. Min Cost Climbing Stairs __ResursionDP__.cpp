/*
    Problems Link : https://leetcode.com/problems/min-cost-climbing-stairs/
    TC - O(n)
    SC - O(n) + O(n) Recursion Stuck Memory
*/
class Solution {
private:
    int helper(int idx, vector<int>& cost, vector<int>& DP){
        if(idx == cost.size()){
            return 0;
        }
        
        int& cache = DP[idx];
        if(cache != -1){
            return cache;
        }
        
        int way1 = 0, way2 = INT_MAX;
        way1 = cost[idx] + helper(idx+1, cost, DP);
        if(idx+2 <= cost.size()){
            way2 = cost[idx] + helper(idx+2, cost, DP);
        }
        return cache = min(way1, way2);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> DP(n+1, -1);
        int result = helper(0, cost, DP);
        fill(DP.begin(), DP.end(), -1);
        result = min(result, helper(1, cost, DP));
        return result;
    }
};