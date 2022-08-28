class Solution {
public:
	// TC : O(log(n+m))
	// SC : O(1)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int total = n+m;
        if(n>m){
        	return findMedianSortedArrays(nums2, nums1);
        }

        int low = 0, high = n;
        while(low<=high){
        	int pivot = low + (high-low)/2;
        	int remain = (total+1)/2 - pivot;

        	int left1 = (pivot>0) ? nums1[pivot-1] : INT_MIN;
        	int right1 = (pivot<n) ? nums1[pivot] : INT_MAX; 
        	int left2 = (remain>0) ? nums2[remain-1] : INT_MIN;
        	int right2 = (remain<m) ? nums2[remain] : INT_MAX;

        	if(left1<=right2 && left2<=right1){
        		if(total%2==0){
        			return (max(left1, left2) + min(right1, right2))/2.0;
        		}
        		return max(left1, left2);
        	} else if(left1 > right2) {
        		high = pivot - 1;
        	} else {
        		low = pivot + 1;
        	}
        }
        return -1;

    }
};