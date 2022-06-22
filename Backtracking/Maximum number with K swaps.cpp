// Problem Link : https://www.geeksforgeeks.org/find-maximum-number-possible-by-doing-at-most-k-swaps/
// Topic : Backtracking
// TC : O(n^k) where n is length of string.
// SC : O(n) for store maximum store and o(n) for recursion stack space.


class Solution
{
    private:
    void getMaxValueKSwap(int idx, string str, int k, string& maxVal){
        if(k==0) {
            return;
        }
        int n = str.length();
        
        char maxChar = str[idx];
        for(int i=idx+1; i<n; i++){
            if(maxChar < str[i]){
                maxChar = str[i];
            }
        }
        
        if(maxChar != str[idx]) --k;
        
        for(int i=n-1; i>=idx; i--){
            if(maxChar==str[i]){
                swap(str[idx], str[i]);
                
                if(str.compare(maxVal)>0){
                    maxVal = str;
                }
                getMaxValueKSwap(idx+1, str, k, maxVal);
                swap(str[idx], str[i]);
            }
        }
    }
    public:
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       string maxVal = str;
       getMaxValueKSwap(0, str, k, maxVal);
       return maxVal;
    }
};