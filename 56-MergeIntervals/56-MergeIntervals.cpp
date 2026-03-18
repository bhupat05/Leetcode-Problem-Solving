// Last updated: 3/18/2026, 3:02:17 PM
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> r;
        r.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            if (r.back()[1] < intervals[i][0]) {
                r.push_back(intervals[i]);
            } else {
                r.back()[1] = max(r.back()[1], intervals[i][1]);
            }
        }

        return r;
    }
};
