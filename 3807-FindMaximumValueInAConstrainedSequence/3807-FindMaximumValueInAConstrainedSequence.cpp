// Last updated: 3/18/2026, 2:20:39 PM
class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        sort(restrictions.begin(), restrictions.end());

        vector<long long> a(n, LLONG_MAX);
        
        a[0] = 0;

        for(auto &it : restrictions) {
            int idx = it[0];
            int val = it[1];
            a[idx] = min(a[idx], (long long) val);
        }

        for(int i = 1; i < n; i++) {
            a[i] = min(a[i], a[i - 1] + diff[i - 1]);
        }

        for(int i = n - 2; i >= 0; i--) {
            a[i] = min(a[i], a[i + 1] + diff[i]);
        }

        long long r = 0;
        for(long long x : a) {
            r = max(r, x);
        } 
        return r;
        
    }
};