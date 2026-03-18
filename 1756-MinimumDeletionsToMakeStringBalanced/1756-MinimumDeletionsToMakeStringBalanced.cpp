// Last updated: 3/18/2026, 2:24:00 PM
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();

        vector<int> a(n, 0), b(n, 0);

        b[0] = (s[0] == 'b');
        a[n - 1] = (s[n - 1] == 'a');

        for(int i = 1; i < n; i++)
            b[i] = b[i - 1] + (s[i] == 'b');

        for(int i = n - 2; i >= 0; i--)
            a[i] = a[i + 1] + (s[i] == 'a');

        int mini = min(a[0], b[n - 1]);  

        for(int i = 0; i < n - 1; i++)
            mini = min(mini, b[i] + a[i + 1]);

        return mini;
    }
};
