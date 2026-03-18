// Last updated: 3/18/2026, 2:25:57 PM
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> dist(n * n + 1, -1);
        queue<int> q;

        dist[1] = 0;
        q.push(1);

        auto get = [&](int x) {
            int r = (x - 1) / n;
            int c = (x - 1) % n;
            if (r % 2 == 1) c = n - 1 - c;
            return board[n - 1 - r][c];
        };

        while (!q.empty()) {
            int cur = q.front(); q.pop();

            for (int d = 1; d <= 6 && cur + d <= n * n; d++) {
                int nxt = cur + d;
                int jump = get(nxt);
                if (jump != -1) nxt = jump;

                if (dist[nxt] == -1) {
                    dist[nxt] = dist[cur] + 1;
                    if (nxt == n * n) return dist[nxt];
                    q.push(nxt);
                }
            }
        }
        return -1;
    }
};
