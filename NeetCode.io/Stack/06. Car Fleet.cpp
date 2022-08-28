class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int cars = position.size();
        
        vector<pair<int, int>> pairs;
        vector<double> timeToReach(cars);
        for(int i=0; i<cars; i++){
            pairs.push_back({position[i], speed[i]});
        }
        sort(pairs.begin(), pairs.end());
        
        for(int i=0; i<cars; i++){
            double need = (double)((target-pairs[i].first)*1.0/pairs[i].second);  
            timeToReach[i] = need;
        }
        stack<double> cache;
        for(int i=cars-1; i>=0; i--){
            double currReachTime = timeToReach[i];
            if(cache.empty() || cache.top()<currReachTime){
                cache.push(currReachTime);
            }
        }
        return cache.size();
    }
};