// Last updated: 3/18/2026, 2:23:36 PM
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int maxValues[3];

        for(auto &triplet : triplets){
            if(triplet[0] <= target[0] && triplet[1] <= target[1] && triplet[2] <= target[2]){
                maxValues[0] = max(maxValues[0], triplet[0]);
                maxValues[1] = max(maxValues[1], triplet[1]);
                maxValues[2] = max(maxValues[2], triplet[2]);
            }
        }
        return maxValues[0] == target[0] && maxValues[1] == target[1] && maxValues[2] == target[2];
    }
};