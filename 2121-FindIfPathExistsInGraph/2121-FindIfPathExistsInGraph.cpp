// Last updated: 3/18/2026, 2:23:23 PM
class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int root(int p) {
        if (parent[p] != p) {
            parent[p] = root(parent[p]); // path compression
        }
        return parent[p];
    }

    void unite(int p, int q) {
        int rootX = root(p);
        int rootY = root(q);

        if (rootX == rootY) return;

        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        }
        else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        }
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        parent.resize(n);
        rank.resize(n, 0);
        
        // initialize parent[i] = i
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        // unite edges
        for (auto& edge : edges) {
            unite(edge[0], edge[1]);
        }

        return root(source) == root(destination);
    }
};
