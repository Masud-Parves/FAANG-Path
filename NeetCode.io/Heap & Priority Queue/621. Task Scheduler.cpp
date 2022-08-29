class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int>cache;
        for(auto& task : tasks){
            cache[task]++;
        }
        
        priority_queue<int> Q;
        for(auto& freq : cache){
            Q.push(freq.second);
        }
        
        queue<pair<int, int>> waiting;
        
        int time = 0, currTask=-1, currTaskIdleTime = 0;
        while(!Q.empty() || !waiting.empty()){
            if(!waiting.empty()){
                int idleTime = waiting.front().second;
                if(idleTime == time) {
                    Q.push(waiting.front().first);
                    waiting.pop();
                }
            }

            if(!Q.empty()){
                currTask = Q.top();
                Q.pop();
                currTaskIdleTime = time+n+1;
                if(--currTask>0){
                    waiting.push({currTask, currTaskIdleTime});
                }   
            }
            time++;
        }
        return time;
    }
};