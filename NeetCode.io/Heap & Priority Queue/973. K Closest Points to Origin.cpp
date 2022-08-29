class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;
        if(k == 0 or points.size() == 0) {
            return result;
        }
        
        priority_queue<pair<double, vector<int>>>pq;
        
        for(auto& point : points){
            double distance = sqrt((point[0]*point[0] + point[1]*point[1]));
            
            pq.push({distance, point});
            
            if(pq.size()>k){
                pq.pop();
            }
        }
        
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};