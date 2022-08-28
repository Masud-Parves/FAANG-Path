class Solution {
public:
	// TC : O(n+e) where n is number of recepies and e number of ingredients given
	// SC : O(n+e)
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int numOfRecipes = recipes.size();
        vector<string> result;
        unordered_map<string, int> indegree;
        queue<string>Q;
        for(auto& supply : supplies){
            indegree[supply] = 0;
            Q.push(supply);
        }
        
        unordered_map<string, vector<string>> graph;
        for(int i=0; i<ingredients.size(); i++){
            for(int k=0; k<ingredients[i].size(); k++){
                graph[ingredients[i][k]].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }
        
        while(!Q.empty()){
            string supply = Q.front();
            Q.pop();
            
            for(auto& cooking : graph[supply]){
                indegree[cooking]--;
                if(indegree[cooking] == 0) {
                    Q.push(cooking);
                    result.push_back(cooking);
                }
            }
        }
        return result;
    }
};