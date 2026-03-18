// Last updated: 3/18/2026, 2:20:26 PM
class Solution {
public:
    static constexpr int NEG = -1000000000;

    int B;
    vector<vector<int>> g;
    vector<int> present, future;
    vector<vector<int>> dp0, dp1;

    vector<int> merge(const vector<int>& a, const vector<int>& b) {
        vector<int> res(B + 1, NEG);
        for (int i = 0; i <= B; i++) {
            if (a[i] == NEG) continue;
            for (int j = 0; j + i <= B; j++) {
                if (b[j] == NEG) continue;
                res[i + j] = max(res[i + j], a[i] + b[j]);
            }
        }
        return res;
    }

    void dfs(int u) {
        dp0[u].assign(B + 1, NEG);
        dp1[u].assign(B + 1, NEG);
        dp0[u][0] = dp1[u][0] = 0;

        for (int v : g[u]) {
            dfs(v);
            dp0[u] = merge(dp0[u], dp0[v]);
            dp1[u] = merge(dp1[u], dp0[v]);
        }

        vector<int> buy0(B + 1, NEG), buy1(B + 1, NEG);
        int c0 = present[u];
        int c1 = present[u] / 2;

        if (c0 <= B) buy0[c0] = future[u] - c0;
        if (c1 <= B) buy1[c1] = future[u] - c1;

        for (int v : g[u]) {
            buy0 = merge(buy0, dp1[v]);
            buy1 = merge(buy1, dp1[v]);
        }

        for (int i = 0; i <= B; i++) {
            dp0[u][i] = max(dp0[u][i], buy0[i]);
            dp1[u][i] = max(dp1[u][i], buy1[i]);
        }
    }

    int maxProfit(int n, vector<int>& p, vector<int>& f,
                  vector<vector<int>>& hierarchy, int budget) {
        present = p;
        future = f;
        B = budget;

        g.assign(n, {});
        dp0.resize(n);
        dp1.resize(n);

        for (auto &e : hierarchy)
            g[e[0] - 1].push_back(e[1] - 1);

        dfs(0); 

        return *max_element(dp0[0].begin(), dp0[0].end());
    }
};
