class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	int n = s.size();
    	unordered_map<char, int> seen;
    	int L = 0, longest = 0;
    	for(int i=0; i<n; i++){
    		seen[s[i]]++;
    		if(seen[s[i]]>1){
    			while(seen[s[i]]>1) {
    				seen[s[L]]--;
    				L++;
    			}
    		}
            longest = max(longest, i-L+1);
    	}
    	return longest;
    }
};