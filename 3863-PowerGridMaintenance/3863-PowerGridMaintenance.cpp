// Last updated: 3/18/2026, 2:20:22 PM
class Solution {
    vector<int> parent; // DSU array to track each station’s parent (which group/grid it belongs to)

    // Function to find the leader (root parent) of a node using path compression
    int findParent(int x)
    {
        if (parent[x] == x) 
            return x;              // If a node is its own parent, it's the leader of its group
        return parent[x] = findParent(parent[x]); 
        // Otherwise, recursively find its leader and compress the path for efficiency
    }

public:
    vector<int> processQueries(int c, vector<vector<int>>& conn, vector<vector<int>>& queries) {
        // Step 1: Initialize DSU — each station is its own parent at the start
        parent.resize(c + 1);
        for (int i = 0; i < c + 1; i++)
            parent[i] = i;

        // Step 2: Union all connected stations to form grids (connected components)
        for (int i = 0; i < conn.size(); i++)
        {
            int p1 = findParent(conn[i][0]); // leader of first station
            int p2 = findParent(conn[i][1]); // leader of second station
            parent[p1] = p2; // merge the two sets (connect both grids)
        }

        // Step 3: Create a map of grid leader → set of online stations in that grid
        unordered_map<int, set<int>> mp;

        for (int i = 0; i < parent.size(); i++)
        {
            findParent(i);              // make sure each station points directly to its leader
            mp[parent[i]].insert(i);    // add station i to its leader’s set of stations
        }

        // Step 4: Process each query
        vector<int> ans; // to store results for all type 1 (maintenance) queries

        for (int i = 0; i < queries.size(); i++)
        {
            int x = queries[i][1]; // station number

            // Type 1 query: maintenance check
            if (queries[i][0] == 1)
            {
                // Case 1: if station x is still online (exists in the set)
                if (mp[parent[x]].count(x))
                    ans.push_back(x);  // it handles the check itself

                // Case 2: if no online stations exist in this grid
                else if (mp[parent[x]].size() == 0)
                    ans.push_back(-1); // nobody can handle it

                // Case 3: station x is offline but others in its grid are online
                else {
                    auto itr = mp[parent[x]].begin(); // smallest online station ID
                    ans.push_back(*itr);
                }
            }
            // Type 2 query: turn station x offline
            else
                mp[parent[x]].erase(x); // remove x from the grid’s set (mark offline)
        }

        // Step 5: return results of all maintenance queries
        return ans;
    }
};
