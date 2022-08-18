/*
    Problems Link : https://leetcode.com/problems/coin-change/
    TC - O(n*weight)
    SC - O(weight)
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>previousRow(amount+1, INT_MAX/2), currentRow(amount+1, INT_MAX/2);
        
        for(int cash=0; cash<=amount; cash++){
            if(cash%coins[0] == 0) previousRow[cash] = cash/coins[0];
            else previousRow[cash] = INT_MAX/2;
        }

        for(int idx=1; idx<n; idx++){
            for(int cash=0; cash<=amount; cash++){
                int non_pick = previousRow[cash], pick = INT_MAX/2; 
                if(cash>=coins[idx]){
                    pick = 1 + currentRow[cash-coins[idx]];
                }
                currentRow[cash] = min(pick, non_pick);
            }
            previousRow = currentRow;
        }
        return (previousRow[amount] == INT_MAX/2) ? -1 : previousRow[amount];
    }
};