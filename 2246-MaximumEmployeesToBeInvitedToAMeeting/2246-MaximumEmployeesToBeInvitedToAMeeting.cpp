// Last updated: 3/18/2026, 2:23:02 PM
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int BFS(int start, unordered_map<int, vector<int>>& adj, vector<bool>& visited) {
        queue<pair<int, int>> que;
        que.push({start, 0});
        int maxdistance = 0;

        while (!que.empty()) {
            auto [curr, dist] = que.front();
            que.pop();

            for (auto &ngbr : adj[curr]) {
                if (!visited[ngbr]) {
                    visited[ngbr] = true;
                    que.push({ngbr, dist + 1});
                    maxdistance = max(maxdistance, dist + 1);
                }
            }
        }
        return maxdistance;
    }

    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < n; i++) {
            int u = i;
            int v = favorite[i];

            adj[v].push_back(u);
        }

        int longestcycle = 0;
        int happy = 0;

        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                unordered_map<int, int> mp;

                int curr = i;
                int currcount = 0;

                while (!visited[curr]) {
                    visited[curr] = true;
                    mp[curr] = currcount;

                    int nextnode = favorite[curr];
                    currcount += 1;

                    if (mp.count(nextnode)) {
                        int cyclelength = currcount - mp[nextnode];
                        longestcycle = max(longestcycle, cyclelength);

                        if (cyclelength == 2) {
                            vector<bool> visitednodes(n, false);
                            visitednodes[curr] = true;
                            visitednodes[nextnode] = true;
                            happy += 2 + BFS(curr, adj, visitednodes) + BFS(nextnode, adj, visitednodes);
                        }
                        break;
                    }
                    curr = nextnode;
                }
            }
        }
        return max(happy, longestcycle);
    }
};
