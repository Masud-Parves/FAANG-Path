class Solution {
private:
    int helper(int idx, vector<int>& nums, vector<int>& DP){
        if(idx == nums.size()-1){
            return 1;
        }
        if(idx>=nums.size()){
            return 0;
        }
        
        int& cache = DP[idx];
        if(cache != -1){
            return cache;
        }
        int back = 0;
        for(int i=1; i<=nums[idx]; i++){
            back = helper(idx+i, nums, DP);
            if(back == 1) break;
        }
        return cache = back;
    }
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int>DP(n, 0);
        
        DP[n-1] = 1;
        for(int i=n-2; i>=0; i--){
            DP[i] = 0;
            for(int k=1; k<=nums[i] ; k++){
                if(i+k<n)
                    DP[i] = DP[i+k];
                if(DP[i] == 1) break;
            }
        }
        
        
        return DP[0];
    }
};