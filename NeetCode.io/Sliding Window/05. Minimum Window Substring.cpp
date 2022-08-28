class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        string result = "";
        
        unordered_map<char, int>seen;
        for(auto& ch : t){
            seen[ch]++;
        }
        int unique = seen.size();
        int window = INT_MAX;
        int l = 0, done = 0, left =-1, right=-1;
        for(int r= 0; r<n; r++){
            seen[s[r]]--;
            if(seen[s[r]] == 0) unique--;
            
            if(unique == 0){
                while(l<r && seen[s[l]]<0){
                    seen[s[l]]++;
                    l++;
                }
                
                if(r-l+1<window){
                    window = r-l+1;
                    result = s.substr(l, r-l+1);
                }
                
                seen[s[l]]++;
                if(seen[s[l]] == 1) unique++;
                l++;
            } 
            
        }

        return result;
    }
};