/*
    Problems Link : https://leetcode.com/problems/coin-change-2/
    TC - O(n*weight)
    SC - O(n*weight) + O(n) Recursion Stack Memory
*/

class Solution {
private:
    int calculateWays(int idx, int amount, vector<int>& coins, vector<vector<int>>& DP){
        if(amount == 0) return 1;
        if(idx<0 || amount<0){
            return 0;
        }
        
        int & cache = DP[idx][amount];
        if(cache != -1){
            return cache;
        }
        
        int way1 = 0, way2 = 0;
        way1 = calculateWays(idx-1, amount, coins, DP);
        if(coins[idx]<=amount){
            way2 = calculateWays(idx, amount-coins[idx], coins, DP);
        }
        return cache = (way1 + way2);
    }
public:    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        if(amount == 0) return 1;
        vector<vector<int>>DP(n, vector<int>(amount+1, -1));
        return calculateWays(n-1, amount, coins, DP);
    }
};