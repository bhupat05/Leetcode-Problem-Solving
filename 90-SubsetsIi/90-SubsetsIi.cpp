// Last updated: 3/18/2026, 3:01:34 PM
class Solution {
public:
    void solve(int i, vector<vector<int>>& ans, vector<int>& curr, vector<int>& nums) {
            if(i == nums.size()) {
                ans.push_back(curr);
                return;
            }

            curr.push_back(nums[i]);
            solve(i + 1, ans, curr, nums);
            curr.pop_back();

            int idx = i + 1;

            while(idx < nums.size() && nums[idx] == nums[idx - 1]) idx++;

            solve(idx, ans, curr, nums);


    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0, ans, curr, nums);
        return ans; 
    }
};