//Input : k = 3
// [1,3,-1,-3,5,3,6,7]
// ans : 3,

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        int n = nums.size();
        if(k == 1)  return nums;
        deque<int> dq;
        
        for(int i=0; i<n ; i++){
            if(!dq.empty() && dq.front()==i-k){
                dq.pop_front();
            }
            
            while(!dq.empty() && nums[dq.back()]<=nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1) result.push_back(nums[dq.front()]);
        }
        return result;
    }
};
