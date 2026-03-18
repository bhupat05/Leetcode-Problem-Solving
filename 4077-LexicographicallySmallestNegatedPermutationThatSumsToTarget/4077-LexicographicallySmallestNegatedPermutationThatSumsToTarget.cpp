// Last updated: 3/18/2026, 2:19:45 PM
class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        
        long long S = 1LL * n * (n + 1) / 2;

        if (target < -S || target > S) return {};
        if ((S - target) % 2) return {};

        long long D = S - target;  
        
        vector<int> ans(n);
        unordered_set<int> flipped;

        for (int i = n; i >= 1; i--) {
            if (2LL * i <= D) {
                flipped.insert(i);
                D -= 2LL * i;
            }
        }

        if (D != 0) return {};

        for (int i = 1; i <= n; i++) {
            if (flipped.count(i))
                ans[i - 1] = -i;
            else
                ans[i - 1] = i;
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};
