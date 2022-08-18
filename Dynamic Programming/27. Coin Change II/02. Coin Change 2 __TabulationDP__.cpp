/*
    Problems Link : https://leetcode.com/problems/coin-change-2/
    TC - O(n*weight)
    SC - O(n*weight)
*/

class Solution {
public:    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        if(amount == 0) return 1;
        vector<vector<int>>DP(n, vector<int>(amount+1, 0));

        for(int c=0; c<=amount; c++){
        	DP[0][c] = (c%coins[0] == 0);
        }

        for(int idx=1; idx<n; idx++){
        	for(int c=0; c<=amount ; c++){
        		int way1 = DP[idx-1][c], way2=0;
        		if(coins[idx]<=c){
        			way2 = DP[idx][c-coins[idx]];
        		}
                DP[idx][c] = (way1+way2);
        	}
        }

        return DP[n-1][amount];
    }
};