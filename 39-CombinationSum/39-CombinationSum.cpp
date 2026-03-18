// Last updated: 3/18/2026, 3:02:39 PM
class Solution {
public:
    void solve(vector<int>& candidates, int i, int target,
               vector<int>& combination, vector<vector<int>>& ans) {
        
        if (target == 0) {
            ans.push_back(combination);
            return;
        }

        if (i == candidates.size() || target < 0)
            return;

        
        combination.push_back(candidates[i]);
        solve(candidates, i, target - candidates[i], combination, ans); 
        combination.pop_back(); 

        solve(candidates, i + 1, target, combination, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combination;
        solve(candidates, 0, target, combination, ans);
        return ans;
    }
};
