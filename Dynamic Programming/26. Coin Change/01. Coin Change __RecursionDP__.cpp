/*
    Problems Link : https://leetcode.com/problems/coin-change/
    TC - O(n*weight)
    SC - O(n*weight) + O(n) Recursion Stack Memory
*/

class Solution {
private:
    int calculateMinimumCoins(int idx, int amount, vector<int>& coins, int n, vector<vector<int>>& DP){
        if(idx == n-1){
            if(amount%coins[idx]==0) return amount/coins[idx];
            return INT_MAX/2;
        }

        int& cache = DP[idx][amount];
        if(cache != -1){
            return cache;
        }

        int way1 = 0, way2 = INT_MAX/2;
        way1 = calculateMinimumCoins(idx+1, amount, coins, n, DP);
        if(coins[idx]<=amount){
            way2 = 1 + calculateMinimumCoins(idx, amount-coins[idx], coins, n, DP);
        }
        return cache = min(way1, way2);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> DP(n, vector<int>(amount+1, -1));
        int result = calculateMinimumCoins(0, amount, coins, n, DP);
        return (result == INT_MAX/2) ? -1 : result;
    }
};