// Last updated: 3/18/2026, 2:23:22 PM
class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa != pb) parent[pa] = pb;
    }

    bool gcdSort(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        parent.resize(maxVal + 1);
        for (int i = 0; i <= maxVal; i++) parent[i] = i;

        vector<int> spf(maxVal + 1);
        for (int i = 2; i <= maxVal; i++) {
            if (spf[i] == 0) {
                for (int j = i; j <= maxVal; j += i) {
                    if (spf[j] == 0) spf[j] = i;
                }
            }
        }

        for (int x : nums) {
            int temp = x;
            while (temp > 1) {
                int p = spf[temp];
                unite(x, p);
                while (temp % p == 0) temp /= p;
            }
        }

        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        for (int i = 0; i < nums.size(); i++) {
            if (find(nums[i]) != find(sorted[i]))
                return false;
        }

        return true;
    }
};