class Solution {
public:      
    int findMin(vector<int>& nums) {
        int n = nums.size();
        
        if(nums[0]<=nums.back()) return nums[0];
        int left = 0, right = n-1, mid;
        
        
        while(left<=right){
            mid = left + (right-left)/2;
            if(nums[mid]>nums[mid+1]) return nums[mid+1];
            if(nums[mid]<nums[mid-1]) return nums[mid];
            if(nums[0]<nums[mid]) {
                 left = mid+1;
            } else {
                right = mid -1;
            }
        }
        return -1;
    }
};