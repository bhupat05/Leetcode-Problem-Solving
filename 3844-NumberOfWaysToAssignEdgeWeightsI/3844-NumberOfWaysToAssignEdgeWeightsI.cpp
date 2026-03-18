// Last updated: 3/18/2026, 2:20:30 PM
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long modPow(long long b, int e, int m) {
        long long r = 1, c = b;
        while (e > 0) {
            if (e & 1) r = (r * c) % m;
            c = (c * c) % m;
            e >>= 1;
        }
        return r;
    }

    int assignEdgeWeights(vector<vector<int>>& ed) {
        int n = (int)ed.size() + 1;
        vector<vector<int>> g(n + 1);
        for (auto &x : ed) {
            int u = x[0], v = x[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> p(n + 1, 0), d(n + 1, 0);
        vector<bool> vis(n + 1, false);
        queue<int> q;
        q.push(1);
        vis[1] = true;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : g[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    p[v] = u;
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }

        int md = *max_element(d.begin() + 1, d.end());
        int x = 1;
        for (int i = 1; i <= n; ++i) {
            if (d[i] == md) {
                x = i;
                break;
            }
        }

        int len = 0, cur = x;
        while (cur != 1) {
            len++;
            cur = p[cur];
        }

        if (len == 0) return 1;
        return (int)modPow(2, len - 1, MOD);
    }
};
