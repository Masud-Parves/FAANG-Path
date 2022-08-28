class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        
        vector < int > ret;
        int L = 0, R = (int)nums.size()-1;
        
        while(L<R){
            if(nums[L]+nums[R] == target){
                ret.push_back(L+1);
                ret.push_back(R+1);
                return ret;
            } else if(nums[L]+nums[R]< target) L++;
            else R--;
        }
        
        return ret;
    }
};