// Last updated: 3/18/2026, 2:19:25 PM
class Solution {
public:
    long long minMergeCost(vector<vector<int>>& lists) {
        int n = lists.size();
        int m = 1 << n;
        long long INF = 1e18;
        vector<long long> t(m, INF);

        vector<vector<int>> v(m);
        vector<int> l(m);
        vector<int> md(m);

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    for (int k = 0; k < (int)lists[j].size(); k++) {
                        v[i].push_back(lists[j][k]);
                    }
                }
            }
            
            sort(v[i].begin(), v[i].end());
            
            l[i] = v[i].size();
            md[i] = v[i][(l[i] - 1) / 2];
        }

       
        for (int i = 0; i < n; i++) {
            t[1 << i] = 0;
        }

        for (int i = 1; i < m; i++) {
            if ((i & (i - 1)) == 0) {
                continue;
            }
            for (int j = (i - 1) & i; j > 0; j = (j - 1) & i) {
                int k = i ^ j;
                if (k == 0) {
                    continue;
                }
                long long d = t[j] + t[k];
                long long s = (long long)l[j] + (long long)l[k];
                long long x = md[j] - md[k];
                if (x < 0) {
                    x = -x;
                }
                
                d += s + x;
                
                if (d < t[i]) {
                    t[i] = d;
                }
            }
        }

        return t[m - 1];
    }
};
