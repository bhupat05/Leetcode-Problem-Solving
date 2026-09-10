// Last updated: 9/10/2026, 11:36:51 AM
1class Solution {
2public:
3    int totalFruit(vector<int>& fruits) {
4        int a = -1, b= -1;
5        int l = 0, ans = 0;
6        int cnt = 0;
7
8        for(int i = 0; i < fruits.size(); i++) {
9            if(cnt == 0) {
10                a = i;
11                cnt = 1;
12            } else if(cnt == 1) {
13                if(fruits[i] == fruits[a]) {
14                    a = i;
15                    cnt = 1;
16                } else {
17                    b = i;
18                    cnt = 2;
19                }
20            } else {
21                if(fruits[i] == fruits[a]) {
22                    a = i;
23                } else if(fruits[i] == fruits[b]) {
24                    b = i;
25                } else {
26                    int old = min(a, b);
27                    l = old + 1;
28                    if(a < b) {
29                        a = i;
30                    } else {
31                        b = i;
32                    }
33                }
34            }
35
36            ans = max(ans, i - l + 1);
37        }
38        return ans;
39    }
40};