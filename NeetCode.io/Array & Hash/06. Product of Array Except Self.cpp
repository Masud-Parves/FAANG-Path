// Approach 01 : prefixSum idea

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    	// Time : O(n)
    	// Space : O(n)
        int n = nums.size();
        vector<int> prefixProducts(n, 1);
        vector<int> suffixProducts(n, 1);
        
        for(int i=0; i<n; i++){
            prefixProducts[i] = (i>0) ? prefixProducts[i-1]*nums[i] : nums[i];
        }

        for(int i=n-1; i>=0; i--){
            suffixProducts[i] = (i+1<n) ? suffixProducts[i+1]*nums[i] : nums[i];
        }
        vector<int>result(n);
        for(int i=0; i<n; i++){
            int left = (i>0) ? prefixProducts[i-1] : 1;
            int right = (i+1<n) ? suffixProducts[i+1] : 1;
            result[i] = left*right;
        }
        return result;
    }
};

// Approach 02: Calculate product & divide by self

/*
1. If there are more than one 0s in nums, the result is an array consisting of all 0.
2. If there is a single 0 in nums, then the result is an array consisting of all 0 except at the index where there was 0 in nums, which will contain product of rest of array.
3. If there's no 0 in nums, then the result is an array ans where ans[i] = prod / nums[i] (prod = product of all elements in nums).
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    	// Time : O(n)
    	// Space : O(1)
        int n = nums.size();
        vector<int>result(n, 0);
        int product = 1, zero = 0;
        for(auto& num : nums){
        	if(num == 0) zero++;
        	else product *= num;
        }

        if(zero>1) return result;

        for(int i=0; i<n; i++){
        	if(zero == 1 && nums[i]!=0){
        		result[i] = 0;
        	} else if(zero == 1 && nums[i]==0){
        		result[i] = product;
        	} else {
        		result[i] = product/nums[i];
        	}
        }
        return result;
    }
};