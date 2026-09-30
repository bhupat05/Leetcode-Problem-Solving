// Last updated: 9/30/2026, 1:19:15 PM
1class Solution {
2public:
3    vector<int> maxDepthAfterSplit(string seq) {
4        int n = seq.size();
5
6        vector<int> ans(n, 0);
7
8        int depth = 0;
9
10        for (int i = 0; i < n; i++) {
11            if (seq[i] == '(') {
12                depth++;
13
14                if (depth % 2 == 1) {
15                    ans[i] = 0;
16                }
17                else {
18                    ans[i] = 1;
19                }
20            }
21            else {
22                if (depth % 2 == 1) {
23                    ans[i] = 0;
24                }
25                else {
26                    ans[i] = 1;
27                }
28
29                depth--;
30            }
31        }
32
33        return ans;
34    }
35};