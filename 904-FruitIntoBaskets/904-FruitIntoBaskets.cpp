// Last updated: 9/10/2026, 11:41:19 AM
1class Solution {
2public:
3    int totalFruit(vector<int>& fruits) {
4        int a = -1, b = -1;   
5        int left = 0;
6        int ans = 0;
7
8        for (int i = 0; i < fruits.size(); i++) {
9            if (a == -1) {
10                a = i;
11            }
12            else if (fruits[i] == fruits[a]) {
13                a = i;
14            }
15            else if (b == -1) {
16                b = i;
17            }
18
19            else if (fruits[i] == fruits[b]) {
20                b = i;
21            }
22
23            else {
24                left = min(a, b) + 1;
25
26                if (a < b)
27                    a = i;
28                else
29                    b = i;
30            }
31
32            ans = max(ans, i - left + 1);
33        }
34
35        return ans;
36    }
37};
38
39