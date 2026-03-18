// Last updated: 3/18/2026, 2:29:50 PM
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<double, int> mp;
            int vertical = 0;
            int currMax = 0;

            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];

                if (x1 == x2) {
                    vertical++;
                    currMax = max(currMax, vertical);
                } else {
                    double slope = (double)(y2 - y1) / (x2 - x1);
                    mp[slope]++;
                    currMax = max(currMax, mp[slope]);
                }
            }

            ans = max(ans, currMax + 1);
        }

        return ans;
    }
};
