// Last updated: 3/18/2026, 3:02:35 PM
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> l(n);
        vector<int> r(n);
        int maxi = 0;
        l[0] = height[0];
        r[n - 1] = height[n - 1];

        for(int i = 1; i < n; i++) {
            l[i] = max(height[i], l[i - 1]);
        }
        for(int i = n - 2; i >= 0; i--) {
            r[i] = max(height[i], r[i + 1]);
        }

        for(int i = 1; i < n - 1; i++) {
            if(height[i] < l[i] && height[i] < r[i]) {
                maxi += min(l[i], r[i]) - height[i];
            }
        }
        return maxi;
    }
};