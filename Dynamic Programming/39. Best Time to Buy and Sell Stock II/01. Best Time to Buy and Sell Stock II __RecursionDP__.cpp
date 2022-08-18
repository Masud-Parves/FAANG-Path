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
private:
    int helper(int idx, int buy, vector<int>& prices, vector<vector<int>>& DP){
        if(idx == prices.size()){
            return 0;
        }
        
        int& cache = DP[idx][buy];
        if(cache != -1){
            return cache;
        }
        
        cache = 0;
        if(buy == 0){
            cache = max(-prices[idx]+helper(idx+1, 1-buy, prices, DP), helper(idx+1, buy, prices, DP));
        } else {
            cache = max(prices[idx]+helper(idx+1, 1-buy, prices, DP), helper(idx+1, buy, prices, DP));
        }
        return cache;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> DP(n, vector<int>(2, -1));
        return helper(0, 0, prices, DP);
    }
};