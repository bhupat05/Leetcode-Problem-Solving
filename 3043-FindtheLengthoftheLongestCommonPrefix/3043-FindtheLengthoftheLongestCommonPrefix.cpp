// Last updated: 5/21/2026, 8:39:49 AM
1class Solution {
2public:
3    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
4        unordered_set<string> prefixes;
5
6        for (int num : arr1) {
7            string s = to_string(num);
8            string pref = "";
9
10            for (char c : s) {
11                pref += c;
12                prefixes.insert(pref);
13            }
14        }
15
16        int ans = 0;
17
18        for (int num : arr2) {
19            string s = to_string(num);
20            string pref = "";
21
22            for (int i = 0; i < s.size(); i++) {
23                pref += s[i];
24
25                if (prefixes.count(pref)) {
26                    ans = max(ans, i + 1);
27                }
28            }
29        }
30
31        return ans;
32    }
33};