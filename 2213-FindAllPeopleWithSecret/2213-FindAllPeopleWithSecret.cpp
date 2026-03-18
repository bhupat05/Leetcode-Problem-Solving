// Last updated: 3/18/2026, 2:23:14 PM
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        
        sort(meetings.begin(), meetings.end(),
            [](const vector<int>& a, const vector<int>& b) {
                return a[2] < b[2];
            }
        );

        unordered_set<int> st = {0, firstPerson};
        int i = 0;
        int m = meetings.size();

        while(i < m) {
            int timeGroup = meetings[i][2];

            unordered_map<int, vector<int>> graph;
            unordered_set<int> par;

            while(i < m && meetings[i][2] == timeGroup) {
                int a = meetings[i][0];
                int b = meetings[i][1];

                graph[a].push_back(b);
                graph[b].push_back(a);
                par.insert(a);
                par.insert(b);
                i++;
            }
            
            queue<int> q;
            unordered_set<int> visited;

            for(int p : par) {
                if(st.count(p)) {
                    q.push(p);
                    visited.insert(p);
                }
            }

            while(!q.empty()) {
                int u = q.front(); 
                q.pop();

                st.insert(u);

                for(int v : graph[u]) {
                    if(!visited.count(v)) {
                        visited.insert(v);
                        q.push(v);
                    }
                }
            }

        }

        return vector<int> (st.begin(), st.end());
    }
};