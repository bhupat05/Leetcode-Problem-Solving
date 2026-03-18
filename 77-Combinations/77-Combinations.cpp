// Last updated: 3/18/2026, 3:01:50 PM
class Solution {
public:
    void solve(int idx, int n, int k, vector<int>& ans, vector<vector<int>>& r) {
        if(ans.size() == k) {
            r.push_back(ans);
            return;
        }

        for(int i = idx; i <= n; i++) {
            ans.push_back(i);
            solve(i + 1, n, k, ans, r);
            ans.pop_back();

        }
    }
    vector<vector<int>> combine(int n, int k) {
       vector<vector<int>> r;
       vector<int> ans;
       solve(1, n, k, ans, r); 
       return r;
    }
};