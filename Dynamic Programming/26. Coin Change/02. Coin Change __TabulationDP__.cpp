/*
    Problems Link : https://leetcode.com/problems/coin-change/
    TC - O(n*weight)
    SC - O(n*weight)
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> DP(n, vector<int>(amount+1, INT_MAX/2));
        
        for(int cash=0; cash<=amount; cash++){
            if(cash%coins[0] == 0) DP[0][cash] = cash/coins[0];
            else DP[0][cash] = INT_MAX/2;
        }

        for(int idx=1; idx<n; idx++){
            for(int cash=0; cash<=amount; cash++){
                int non_pick = DP[idx-1][cash], pick = INT_MAX/2; 
                if(cash>=coins[idx]){
                    pick = 1 + DP[idx][cash-coins[idx]];
                }
                DP[idx][cash] = min(pick, non_pick);
            }
        }
        return (DP[n-1][amount] == INT_MAX/2) ? -1 : DP[n-1][amount];
    }
};