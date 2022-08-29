class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>freq;
        
        for(auto& num : nums){
            freq[num]++;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>Q;
        
        for(auto& f : freq){
            Q.push({f.second, f.first});
            if(Q.size()>k) Q.pop();
        }
        int idx = k-1;
        vector<int>result(k);
        while(!Q.empty()){
            result[idx--] = Q.top().second;
            Q.pop();
        }
        return result;
    }
};