class Solution {
private:
    int getMinimumJump(int idx, vector<int>& nums, vector<int>& memo){
        if(idx>=nums.size()-1) {
            return 0;
        }
        
        if(nums[idx] == 0){
            return INT_MAX;
        }
        
        int& cache = memo[idx];
        if(cache != INT_MAX){
            return cache;
        }
        
        for(int i=1; i<=nums[idx]; i++){
            int currState =  getMinimumJump(idx+i, nums, memo);
            if(currState != INT_MAX){
                cache = min(cache, currState+1);
            }
        }
        return cache;
    }
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>memo(n, INT_MAX);
        int result = getMinimumJump(0, nums, memo);
        return result;
    }
};