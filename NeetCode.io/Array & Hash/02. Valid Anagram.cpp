// use hashmap instend of fixed size because its generic solution for all characters string
// if we used fixed size array it will be count as O(1) space.

// Approach 01 : hash
class Solution {
public:
    bool isAnagram(string s, string t) {
    	// Time : O(n)
        // Spce : O(n)
        // Hint : Two Pass space
    	if(s.size()!=t.size()) return false;
        unordered_map<char, int> cntS, cntT;
        for(int i=0; i<s.size(); i++){
        	cntS[s[i]]++;
            cntT[t[i]]++;
        }
        
        for(auto cnt : cntS){
        	if(cnt.second != cntT[cnt.first]) return false;
        }
        return true;
    }
};

// Approach 02: O(n) hashmap

class Solution {
public:
    bool isAnagram(string s, string t) {
    	// Time : O(n)
        // Spce : O(n)
        // Hint : One O(n) space 
    	if(s.size()!=t.size()) return false;
        unordered_map<char, int> seen;
        for(int i=0; i<s.size(); i++){
        		seen[s[i]]++;
        		seen[t[i]]--;
        }
        
        for(auto m : seen){
        	if(m.second != 0) return false;
        }
        return true;
    }
};


// Approach 03 : Fixed size array

class Solution {
public:
    bool isAnagram(string s, string t) {
    	// Time : O(n)
        // Spce : O(n)
        // Hint : One O(n) space 
    	if(s.size()!=t.size()) return false;
        unordered_map<char, int> seen;
        for(int i=0; i<s.size(); i++){
        		seen[s[i]]++;
        		seen[t[i]]--;
        }
        
        for(auto m : seen){
        	if(m.second != 0) return false;
        }
        return true;
    }
};
