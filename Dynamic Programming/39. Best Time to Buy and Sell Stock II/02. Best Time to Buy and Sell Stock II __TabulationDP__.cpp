/*
    Problems Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
    TC - O(n*2)
    SC - O(n)


	   7
		\     5    6 
		 \    /\  /\
		  \  /  \/  4 --------->[7,1,5,3,6,4]
		   \/	3		  
           1

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> DP(n, vector<int>(2, 0));
        
        DP[n-1][1] = prices[n-1];
        
        for(int idx = n-2; idx>=0; idx--){
            for(int buy=0; buy<=1; buy++){
                if(buy == 0){
                    DP[idx][buy] = max(-prices[idx]+DP[idx+1][1-buy], DP[idx+1][buy]);
                } else {
                    DP[idx][buy] = max(prices[idx]+DP[idx+1][1-buy], DP[idx+1][buy]);
                }
            }
        }
        return DP[0][0];
    }
};