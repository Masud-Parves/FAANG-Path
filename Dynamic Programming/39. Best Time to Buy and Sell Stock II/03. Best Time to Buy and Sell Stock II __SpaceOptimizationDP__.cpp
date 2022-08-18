/*
    Problems Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
    TC - O(n)
    SC - O(1)


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
		int currently_buy = 0, currently_sell = 0, previously_buy = 0, previously_sell = 0;
        previously_sell = prices[n-1];
        for(int idx=n-2; idx>=0; idx--){
            for(int buy = 0; buy<=1; buy++){
                if(buy == 0){
                    // can buy
                    currently_buy = max(-prices[idx]+previously_sell, previously_buy);
                } else {
                    // can sell
                    currently_sell = max(prices[idx]+previously_buy, previously_sell);
                }
            }
            previously_buy = currently_buy;
            previously_sell = currently_sell;
        }
        return currently_buy;
    }
};
