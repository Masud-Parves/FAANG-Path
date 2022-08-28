class Solution {
public:
    bool isValid(string s) {
        int len = s.size();
        
        unordered_map<char, char> bracket;
        bracket['('] = ')';
        bracket['{'] = '}';
        bracket['['] = ']';
        
        stack<char>st;
        
        for(int i=0; i<len ; i++){
            if(st.empty() || s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else {
                if(bracket[st.top()] == s[i]) {
                    st.pop();
                } else return false;
            }
        }
        return st.empty();
    }
};