// Approach 01: Hashmap, Priority Queue

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    	// Time : O(nlogn)
    	// Space : O(n)
  		int n = nums.size();
  		unordered_map<int, int>freq;
  		for(int i=0; i<n; i++){
  			freq[nums[i]]++;
  		}
  		priority_queue<pair<int, int>> Q;
      	for(auto& f : freq){
      		Q.push({f.second, f.first});
     	}
      	vector<int> result;
      	while(k>=1){
      		int element = Q.top().second;
        	Q.pop();
        	result.push_back(element);
      		k--;
      	}
      	return result;
    }
};