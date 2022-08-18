/*
    Problems Link : https://leetcode.com/problems/coin-change-2/
    TC - O(n*weight)
    SC - O(weight)
*/

class Solution {
public:    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        if(amount == 0) return 1;
        vector<int>previousRow(amount+1, 0), currentRow(amount+1, 0);

        for(int c=0; c<=amount; c++){
        	previousRow[c] = (c%coins[0] == 0);
        }

        for(int idx=1; idx<n; idx++){
        	for(int c=0; c<=amount ; c++){
        		int way1 = previousRow[c], way2=0;
        		if(coins[idx]<=c){
        			way2 = currentRow[c-coins[idx]];
        		}
                currentRow[c] = (way1+way2);
        	}
        	previousRow = currentRow;
        }

        return previousRow[amount];
    }
};