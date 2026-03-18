// Last updated: 3/18/2026, 2:23:17 PM
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());

        vector<pair<int, int>> ended;

        for(auto it : events) {
            ended.push_back({it[1], it[2]});
        }

        sort(ended.begin(), ended.end());

        int best = 0;
        int j = 0;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            int start = events[i][0];
            int val = events[i][2];

            while(j < n && ended[j].first < start) {
                best = max(best, ended[j].second);
                j++;
            }

            ans = max(ans, best + val);
            ans = max(ans, val);
        }

        return ans;
    }
};