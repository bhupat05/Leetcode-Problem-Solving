// Last updated: 3/18/2026, 2:22:37 PM
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {

        sort(meetings.begin(), meetings.end());

        vector<int> v(n, 0);

        priority_queue<int, vector<int>, greater<int>> room;
        for(int i = 0; i < n; i++) room.push(i);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, 
                            greater<pair<long long, int>>> pq;

        for(auto& it : meetings) {
            long long start = it[0];
            long long end = it[1];
            long long duration = end - start;

            while(!pq.empty() && pq.top().first <= start) {
                room.push(pq.top().second);
                pq.pop();
            }

            if(!room.empty()) {
                int r = room.top();
                room.pop();
                v[r]++;
                pq.push({end, r});
            } else {
                auto i = pq.top();
                pq.pop();

                long long newEnd = i.first + duration;
                int r = i.second;
                v[r]++;
                pq.push({newEnd, r});
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {
            if(v[i] > v[ans]) {
                ans = i;
            }
        }
        return ans;
    }
};