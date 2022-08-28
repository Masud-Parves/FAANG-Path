class MinStack {
private:
    stack<int>mainStack;
    stack<pair<int, int>>minStack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        mainStack.push(val);
        
        if(minStack.empty() || minStack.top().first>val){
            minStack.push({val,1});
        } else if(minStack.top().first == val){
            minStack.top().second++;
        }
    }
    
    void pop() {
        if(mainStack.empty()) return;
        int val = mainStack.top();
        mainStack.pop();
        if(!minStack.empty() && val == minStack.top().first){
            if(minStack.top().second>1) minStack.top().second--;
            else minStack.pop();
        }
        return;
    }
    
    int top() {
        if(mainStack.empty()) return 0;
        return mainStack.top();
    }
    
    int getMin() {
        if(minStack.empty()) return 0;
        int minValue = minStack.top().first;
        return minValue;
    }
};