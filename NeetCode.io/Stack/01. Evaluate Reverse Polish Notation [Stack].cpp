class Solution {
public:
    int evalRPN(vector<string>& s) {
        int n = s.size();
        stack<int>stack;
        for(int i=0; i<n; i++){
            if(s[i] == "+"){
                int last = stack.top(); stack.pop();
                int secondLast = stack.top(); stack.pop();
                stack.push(last+secondLast);
            }
            else if(s[i] == "-"){
                int last = stack.top(); stack.pop();
                int secondLast = stack.top(); stack.pop();
                stack.push(secondLast-last);
            }
            else if(s[i] == "*"){
                int last = stack.top(); stack.pop();
                int secondLast = stack.top(); stack.pop();
                stack.push(last*secondLast);
            }
            else if(s[i] == "/"){
                int last = stack.top(); stack.pop();
                int secondLast = stack.top(); stack.pop();
                stack.push(secondLast/last);
            }
            else {
                stack.push(stoi(s[i]));
            }
        }
        return stack.top();
    }
};