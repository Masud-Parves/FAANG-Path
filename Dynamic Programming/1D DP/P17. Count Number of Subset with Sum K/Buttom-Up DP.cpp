// Problem Link: https://bit.ly/3B5JBkU

// Time Complexity : O(n*target),  where n is number of elements present in array
// Space Complexity : O(n*target)

// ©Masud Parves

int findWays(vector<int> &nums, int target)
{
    int n = nums.size();
	if(n == 1){
		return target == nums[0] ? 1 : 0;
	}
	vector<vector<int>> DP(n, vector<int>(target+1, 0));

	for(int r=0; r<n; r++){
		DP[r][0] = 1;
	}
	if(nums[0]<=target)
		DP[0][nums[0]] = 1;
	
	for(int r = 1; r<n ; r++){
		for(int c = 1; c<=target; c++){
			DP[r][c] = DP[r-1][c];
			if(nums[r]<=c){
				DP[r][c] += DP[r-1][c-nums[r]];
			}
		}
	}
	return DP[n-1][target];
}