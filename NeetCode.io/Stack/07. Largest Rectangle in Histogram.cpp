class Solution {
private:
    void leftSmallest(vector<int>& heights, vector<int>& left){
        int n = heights.size();
        left.resize(n);
        stack<int> st;
        
        for(int i=0; i<n; i++){
            if(st.empty()){
                left[i] = 0;
            } else if(!st.empty() && heights[st.top()]<heights[i]){
                left[i] = st.top()+1;
            } else {
                while(!st.empty() && heights[st.top()]>=heights[i]){
                    st.pop();
                }
                if(st.empty()){
                    left[i] = 0;
                } else {
                    left[i] = st.top()+1;
                }
            }
            st.push(i);
        }
        return;
    }
    
    void rightSmallest(vector<int>& heights, vector<int>& right){
        int n = heights.size();
        right.resize(n);
        stack<int> st;
        
        for(int i=n-1; i>=0; i--){
            if(st.empty()){
                right[i] = n-1;
            } else if(!st.empty() && heights[st.top()]<heights[i]){
                right[i] = st.top()-1;
            } else {
                while(!st.empty() && heights[st.top()]>=heights[i]){
                    st.pop();
                }
                if(st.empty()){
                    right[i] = n-1;
                } else {
                    right[i] = st.top()-1;
                }
            }
            st.push(i);
        }
        return;
    }
    
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>left;
        vector<int>right;
        leftSmallest(heights, left);
        rightSmallest(heights, right);
        
        int result = 0;
        for(int i=0; i<n; i++){
            //cout << left[i] << " " << right[i] << endl;
            result = max(result, heights[i]*(right[i]-left[i]+1));
        }
        return result;
    }
};