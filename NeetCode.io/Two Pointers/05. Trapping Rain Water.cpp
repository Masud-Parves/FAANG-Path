class Solution {
public:
    int trap(vector<int>& height) {
        int L = 0, R = height.size()-1;
        int left_max = 0, right_max=0, traped_water = 0;
        
        while(L<R){
            left_max = max(left_max, height[L]);
            right_max = max(right_max, height[R]);
            
            if(height[L]<height[R]){
                traped_water += min(left_max, height[R]) - height[L];
                L++;
            } else {
                traped_water += min(right_max, height[L]) - height[R];
                R--;
            }
        }
        return traped_water;
    }
};