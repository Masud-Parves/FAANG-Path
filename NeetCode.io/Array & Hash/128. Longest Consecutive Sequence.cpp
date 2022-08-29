class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return n;
        
        unordered_set<int>nums_set;
        for(auto& num: nums){
            nums_set.insert(num);
        }
        int result = 0;
        for(auto& num : nums){
            if(!nums_set.count(num-1)){
                int currNum = num;
                int count = 1;
                while(nums_set.count(currNum+1)){
                    count++;
                    nums_set.erase(currNum);
                    currNum++;
                }
                result = max(count, result);
            }
        }
        return result;
    }
};