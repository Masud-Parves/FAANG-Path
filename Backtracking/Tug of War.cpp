#include<bits/stdc++.h>

using namespace std;

void getMinimumDiff(int idx, vector<int>& nums, int takenSum, int totalSum, int countTaken, int& result) {
    if(idx == nums.size()){
        if(countTaken == nums.size()/2){
            result = min(result, abs(totalSum - 2*takenSum));
        }
        return;
    }
    
    getMinimumDiff(idx+1, nums, takenSum, totalSum, countTaken, result);
    getMinimumDiff(idx+1, nums, takenSum + nums[idx], totalSum, countTaken+1, result);
}

int tugOfWar(vector<int>& nums, int n)
{
    int totalSum = 0;
    for(auto& num : nums) {
        totalSum += num;
    }
    int result = INT_MAX;
    vector<int> segment;
    getMinimumDiff(0, nums, 0, totalSum, 0, result);
    return result;
}