// Last updated: 7/24/2026, 6:04:58 PM
1class Solution {
2public:
3    int characterReplacement(string s, int k) {
4        int n = s.size();
5        int ans = 0;
6        int maxi = 0;
7        int l = 0;
8        vector<int> v(26, 0);
9
10        for (int i = 0; i < n; i++) {
11            v[s[i] - 'A']++;
12            maxi = max(maxi, v[s[i] - 'A']);
13
14            while ((i - l + 1) - maxi > k) {
15                v[s[l] - 'A']--;
16                l++;
17            }
18
19            ans = max(ans, i - l + 1);
20        }
21
22        return ans;
23    }
24};