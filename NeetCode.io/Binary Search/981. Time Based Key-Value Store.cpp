class TimeMap {
private:
    unordered_map<string, vector<pair<string, int>>> cache;
public:
    TimeMap() {
        cache.clear();
    }
    
    void set(string key, string value, int timestamp) {
        cache[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if(cache.find(key) == cache.end()) return "";
        
        int low = 0, high = cache[key].size()-1, pivot;
        while(low<=high){
            pivot = low + (high - low)/2;
            if(cache[key][pivot].second == timestamp){
                return cache[key][pivot].first;
            } else if(cache[key][pivot].second < timestamp){
                low = pivot+1;
            } else {
                high = pivot-1;
            }
        }

        if(high>=0) return cache[key][high].first;
        return "";
    }
};