// Problem Link: https://bit.ly/3B5JBkU

// Time Complexity : O(n*target),  where n is number of elements present in array
// Space Complexity : O(n*target) + O(n) ~ O(n*targer)
// O(n), where for Recursion Auxiliary Stack Space.

// ©Masud Parves
int calculateNumSubsets(int idx, int target, vector<int>& nums, vector<vector<int>>& DP){
	if(target == 0) {
		return 1;
	}
	
	if(idx < 0) return 0;
	
	int &cache = DP[idx][target];
	if(cache != -1) {
		return cache;
	}
	
	int pick = 0, not_pick;
	
	if(nums[idx] <= target){
		pick = calculateNumSubsets(idx-1, target-nums[idx], nums, DP);
	}
	not_pick = calculateNumSubsets(idx-1, target, nums, DP);
	return cache = pick+not_pick;
}

int findWays(vector<int> &nums, int target)
{
    int n = nums.size();
	if(n == 1){
		return target == nums[0] ? 1 : 0;
	}
	vector<vector<int>> DP(n, vector<int>(target+1, -1));
	return calculateNumSubsets(n-1, target, nums, DP);
}