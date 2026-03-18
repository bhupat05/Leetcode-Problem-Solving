// Last updated: 3/18/2026, 2:27:17 PM
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = capital.size();

        vector<pair<int,int>> vp;
        priority_queue<int> pq;

        for(int i = 0; i < n; i++) {
            vp.push_back({capital[i], profits[i]});
        }

        sort(vp.begin(), vp.end()); 

        int idx = 0;

        while(k) {
            while(idx < n && vp[idx].first <= w) {
                pq.push(vp[idx].second);
                idx++;
            }

            if(pq.empty()) break;

            w += pq.top();
            pq.pop();
            k--;
        }

        return w;
    }
};
