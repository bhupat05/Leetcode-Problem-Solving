// Last updated: 3/18/2026, 2:20:18 PM
class Solution {
public:
    int minDeletion(string s, int k) {
        vector<int> f(26, 0);
        for (char c : s) {
            f[c - 'a']++;
        }

        vector<int> c;
        for (int i : f) {
            if (i > 0) c.push_back(i);
        }

        int d = c.size(); 
        if (d <= k) return 0; 

        sort(c.begin(), c.end()); 
        int del = 0;

        for (int i = 0; i < d - k; i++) {
            del += c[i]; 
        }

        return del;
    }
};
