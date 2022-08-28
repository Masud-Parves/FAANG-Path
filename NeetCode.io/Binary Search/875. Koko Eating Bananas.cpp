class Solution {
private:
    bool check(vector<int>& piles, int k, int h){
        long int hours = 0;
        for (int i = 0; i < piles.size(); i++) {
            hours += ceil((double) piles[i] / k);
        }
        return hours<=h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        
        int low = 1;
        int high = 0;
        for (int i = 0; i < n; i++) {
            high = max(high, piles[i]);
        }
        
        while (low < high) {
            int k = low + (high - low) / 2;
            if (check(piles, k, h)) {
                high = k;
            } else {
                low = k + 1;
            }
        }
        return high;
    }
};