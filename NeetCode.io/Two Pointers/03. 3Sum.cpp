class Solution {
private:
    void twoSum(int i, vector<int>& nums, vector<vector<int>>& triplets){
        int L = i+1, R = nums.size() -1;
        int target =- nums[i];
        
        while(L<R){
            if(nums[L] + nums[R] == target){
                triplets.push_back({nums[i], nums[L], nums[R]});
                while(L<R && nums[L] == nums[L+1]) L++;
                while(L<R && nums[R] == nums[R-1]) R--;
                L++;
                R--;
            } else if(nums[L] + nums[R] < target) L++;
            else R--;
        }
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; i++){
            if(i==0 || nums[i] != nums[i-1]){
                twoSum(i, nums, triplets);
            }
        }
        return triplets;
    }
};