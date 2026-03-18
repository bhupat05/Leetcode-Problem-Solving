// Last updated: 3/18/2026, 3:01:48 PM
class Solution {
public:
    
    void solve(vector<int> &nums,vector<int> &ans, int i, vector<vector<int>> &r){
        if(i == nums.size()){
            r.push_back(ans);
            return ;
        }
        ans.push_back(nums[i]);
        solve(nums, ans, i + 1, r);
        ans.pop_back();
        solve(nums, ans, i + 1, r);

    }
        
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> r;
        vector<int> ans; 
       solve(nums,ans, 0, r);
       return r;
    }
};