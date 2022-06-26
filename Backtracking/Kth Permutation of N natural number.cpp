class Solution {
private:
    void getKthPermutation(string nums, int k, vector<int>& factVal, int n, string& result){
        if(result.size() == n) {
            return;
        }
        
        int idx = k/factVal[nums.size()-1];
        k = k%factVal[nums.size()-1];
        result += nums[idx];
        nums.erase(idx, 1);
        getKthPermutation(nums, k, factVal, n, result);
    }
public:
    string getPermutation(int n, int k) {
        vector<int>factVal = {1,1,2,6,24,120,720,5040,40320,362880};
        string nums ="";
        string result = "";
        for(int i=1; i<=n; i++){
            nums += to_string(i);
        }
        k -= 1;
        getKthPermutation(nums, k, factVal, n, result);
        
        return result;
    }
};