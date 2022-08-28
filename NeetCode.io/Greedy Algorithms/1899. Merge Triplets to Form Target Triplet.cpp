class Solution {
public:
	// TC : O(n)
	// SC : O(1)
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        
        vector<int> result(3);
        for(auto& triplet : triplets){
            if(triplet[0]<=target[0] && triplet[1]<=target[1] && triplet[2]<=target[2]){
                result[0] = max(triplet[0], result[0]);
                result[1] = max(triplet[1], result[1]);
                result[2] = max(triplet[2], result[2]);
            }
        }
        return (result[0] == target[0] && result[1] == target[1] && result[2] == target[2]);
    }
};