// Last updated: 3/18/2026, 2:29:04 PM
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        vector<int> result;

        for (auto &v : prerequisites) {
            int a = v[0], b = v[1];
            adj[b].push_back(a);
            indegree[a]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++)
            if (indegree[i] == 0)
                q.push(i);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            result.push_back(u);

            for (int v : adj[u]) {
                if (--indegree[v] == 0)
                    q.push(v);
            }
        }

        if (result.size() == numCourses)
            return result;

        return {};
    }
};
