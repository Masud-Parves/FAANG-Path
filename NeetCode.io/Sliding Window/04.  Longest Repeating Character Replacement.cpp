class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int mostFreq = 0;
        unordered_map<char, int> seen;
        
        int l = 0, result = 0;
        for(int r=0; r<n; r++){
            seen[s[r]]++;
            mostFreq = max(mostFreq, seen[s[r]]);
            while(r-l+1-mostFreq > k){
                seen[s[l]]--;
                l++;
            }
            result = max(result, r-l+1);
        }
        return result;
    }
};