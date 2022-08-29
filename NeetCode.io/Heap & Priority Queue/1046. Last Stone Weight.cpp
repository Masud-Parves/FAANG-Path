class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto& stone : stones){
            pq.push(stone);
        }
        
        while(pq.size()>1){
            int largest = pq.top();
            pq.pop();
            int secondLargest = pq.top();
            pq.pop();
            
            if(largest != secondLargest){
                pq.push(largest-secondLargest);
            }
        }
        return pq.empty() ? 0 : pq.top();
    }
};