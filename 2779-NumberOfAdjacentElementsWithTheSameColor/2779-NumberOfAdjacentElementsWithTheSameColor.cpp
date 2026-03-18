// Last updated: 3/18/2026, 2:22:10 PM
class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> colors(n, 0);
        vector<int> ans;
        int count = 0;

        for (auto &q : queries) {
            int i = q[0];
            int color = q[1];

            if (colors[i] != 0) {
                if (i > 0 && colors[i] == colors[i - 1]) count--;
                if (i < n - 1 && colors[i] == colors[i + 1]) count--;
            }

            colors[i] = color;

            if (i > 0 && colors[i] == colors[i - 1]) count++;
            if (i < n - 1 && colors[i] == colors[i + 1]) count++;

            ans.push_back(count);
        }

        return ans;
    }
};