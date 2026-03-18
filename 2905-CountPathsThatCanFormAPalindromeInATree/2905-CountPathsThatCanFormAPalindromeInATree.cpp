// Last updated: 3/18/2026, 2:22:05 PM
class Solution {
public:
    vector<vector<int>> adj;
    vector<int> masks;

    void dfs(int node, int mask, string &s) {
        if (node != 0) {
            mask ^= (1 << (s[node] - 'a'));
        }

        masks[node] = mask;

        for (int child : adj[node]) {
            dfs(child, mask, s);
        }
    }

    long long countPalindromePaths(vector<int>& parent, string s) {
        int n = parent.size();
        adj.resize(n);
        masks.resize(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        // Step 1: compute masks
        dfs(0, 0, s);

        // Step 2: count pairs
        unordered_map<int, int> freq;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int mask = masks[i];

            // same mask
            ans += freq[mask];

            // differ by 1 bit
            for (int j = 0; j < 26; j++) {
                ans += freq[mask ^ (1 << j)];
            }

            freq[mask]++;
        }

        return ans;
    }
};