class Solution {
public:
    // TC : O(n)
    // SC : O(n)
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> result;
        unordered_map<char, int> seen;
        for(int i=0; i<n; i++){
            seen[s[i]] = i;
        }
        int maxIdx = -1;
        int last = 0;
        for(int i=0; i<n; i++){
            maxIdx = max(maxIdx, seen[s[i]]);
            if(maxIdx == i){
                result.push_back(i-last + result.empty());
                last = i;
            }
        }
        return result;
    }
};