//Approach 01 : hashmap

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    	// Time : O(n)
    	// Space : O(n)
        unordered_map<int, int> seen;
        for(int i=0; i<nums.size(); i++){
        	if(seen.find(nums[i]) != seen.end()){
        		return true;
        	}
        	seen[nums[i]] = i;
        }
        return false;
    }
};

// Approach 02 : sorting
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    	// Time : O(nlog(n))
    	// Space : O(1)
        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); i++){
        	if(nums[i] == nums[i-1]){
        		return true;
        	}
        }
        return false;
    }
};