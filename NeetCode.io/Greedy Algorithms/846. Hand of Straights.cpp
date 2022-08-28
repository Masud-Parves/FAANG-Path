class Solution {
public:
	// TC - O(NlongN)
	// SC - O(N)
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize != 0) return false;
        
        map<int, int> cache;
        for(auto& card : hand){
            cache[card]++;
        }
        while(!cache.empty()){
            int currCard = cache.begin()->first;
            for(int i=0;  i<groupSize; i++){
                if(cache[currCard+i] == 0){
                    return false;
                }
                cache[currCard+i]--;
                
                if(cache[currCard+i]==0){
                    cache.erase(currCard+i);
                }
            }
        }
        return true;
    }
};