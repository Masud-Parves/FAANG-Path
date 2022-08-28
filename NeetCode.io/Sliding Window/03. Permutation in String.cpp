class Solution {
public:
    bool checkInclusion(string s1, string s) {
        int n = s.size();
        unordered_map<int, int> seen;
        
        for(auto& ch : s1){
            seen[ch]++;
        }
        int unique = seen.size();
        int L = 0, R = 0;
        while(R<n){
            seen[s[R]]--;
            if(seen[s[R]] == 0){
                unique--;
            }
            if(R-L+1 == s1.size()){
                if(unique == 0) return true;
                
                if(seen.find(s[L]) != seen.end()){
                    seen[s[L]]++;
                    if(seen[s[L]] == 1) unique++;
                    L++;
                }
            }
            R++;
        }
        return false;
    }
};