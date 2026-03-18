// Last updated: 3/18/2026, 2:19:36 PM
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> pos(n + 1);

        for(int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        for(int v = 1; v <= n; v++) {
            auto &p = pos[v];
            int m = p.size();

            if(m < 3) continue;

            for(int i = 0; i + 2 < m; i++) {
                int l = p[i];
                int r = p[ i + 2];
                ans = min(ans, 2 * (r - l));
            }
        }

        return ans == INT_MAX ? -1 : ans;

        
    }
};