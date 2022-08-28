class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n);
        stack<pair<int, int>> stack;
        
        for(int i=n-1; i>=0; i--){
            int currVal = temperatures[i];
            
            while(!stack.empty() && currVal>=stack.top().first){
                stack.pop();
            }
            
            result[i] = stack.empty() ? 0 : stack.top().second-i;
            stack.push({currVal, i});
        }
        return result;
    }
};