class Solution {
public:
    int maxArea(vector<int>& height) {
        int L = 0, R = height.size()-1;
        int result = 0;
        while(L<R){
            int wdt = R-L;
            int hdt = min(height[L], height[R]);
            result = max(result, hdt*wdt);
            if(height[L] < height[R]) L++;
            else R--;
        }
        return result;
    }
};