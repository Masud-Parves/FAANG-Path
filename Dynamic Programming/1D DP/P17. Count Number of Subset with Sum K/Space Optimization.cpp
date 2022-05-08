// Problem Link: https://bit.ly/3B5JBkU

// Time Complexity : O(n*target),  where n is number of elements present in array
// Space Complexity : O(target) + O(target) ~ O(targer)

// ©Masud Parves

int findWays(vector<int> &nums, int target)
{
    int n = nums.size();
	if(n == 1){
		return target == nums[0] ? 1 : 0;
	}
	vector<int>previousRow(target+1, 0), currentRow(target+1, 0);

	previousRow[0] = currentRow[0] = 1;
	if(nums[0]<=target)
		previousRow[nums[0]] = 1;
	
	for(int r = 1; r<n ; r++){
		for(int c = 1; c<=target; c++){
			currentRow[c] = previousRow[c];
			if(nums[r]<=c){
				currentRow[c] += previousRow[c-nums[r]];
			}
		}
		previousRow = currentRow;
	}
	return previousRow[target];
}