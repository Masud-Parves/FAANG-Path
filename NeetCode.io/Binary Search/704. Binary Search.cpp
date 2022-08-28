class Solution {
public:
    int search(vector<int>& nums, int target) {
        int L = 0, R = nums.size()-1, mid = 0;
        while(L<=R){
            mid = L + (R-L)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) L = mid+1;
            else R = mid-1;
        }
        return -1;
    }
};