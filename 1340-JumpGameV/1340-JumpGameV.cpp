// Last updated: 5/24/2026, 8:31:00 AM
1class Solution {
2private:
3    vector<int> f;
4
5public:
6    void dfs(vector<int>& arr, int id, int d, int n) {
7        if (f[id] != -1) {
8            return;
9        }
10        f[id] = 1;
11        for (int i = id - 1; i >= 0 && id - i <= d && arr[id] > arr[i]; --i) {
12            dfs(arr, i, d, n);
13            f[id] = max(f[id], f[i] + 1);
14        }
15        for (int i = id + 1; i < n && i - id <= d && arr[id] > arr[i]; ++i) {
16            dfs(arr, i, d, n);
17            f[id] = max(f[id], f[i] + 1);
18        }
19    }
20
21    int maxJumps(vector<int>& arr, int d) {
22        int n = arr.size();
23        f.resize(n, -1);
24        for (int i = 0; i < n; ++i) {
25            dfs(arr, i, d, n);
26        }
27        return *max_element(f.begin(), f.end());
28    }
29};