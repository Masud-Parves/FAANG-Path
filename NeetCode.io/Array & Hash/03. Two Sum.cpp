//Approach 01: Hashmap

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	// Time : O(n)
    	// Space : O(n)

        int n = nums.size();
        unordered_map<int, int>seen;
        for(int i=0; i<n; i++){
        	if(seen.find(target-nums[i]) != seen.end()){
            	return {i, seen[target-nums[i]]};
            }
            seen[nums[i]] = i;
        }
        return {-1, -1};
    }
};
