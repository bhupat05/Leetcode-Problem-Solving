// Last updated: 3/28/2026, 5:49:07 PM
1class Solution {
2public:
3    string findTheString(vector<vector<int>>& lcp) {
4        int n = lcp.size();
5        string word(n, '\0');
6        char current = 'a';
7
8        for (int i = 0; i < n; i++) {
9            if (word[i] == '\0') {
10                if (current > 'z') {
11                    return "";
12                }
13                word[i] = current;
14                for (int j = i + 1; j < n; j++) {
15                    if (lcp[i][j] > 0) {
16                        word[j] = word[i];
17                    }
18                }
19                current++;
20            }
21        }
22
23        for (int i = n - 1; i >= 0; i--) {
24            for (int j = n - 1; j >= 0; j--) {
25                if (word[i] != word[j]) {
26                    if (lcp[i][j]) {
27                        return "";
28                    }
29                } else {
30                    if (i == n - 1 || j == n - 1) {
31                        if (lcp[i][j] != 1) {
32                            return "";
33                        }
34                    } else {
35                        if (lcp[i][j] != lcp[i + 1][j + 1] + 1) {
36                            return "";
37                        }
38                    }
39                }
40            }
41        }
42
43        return word;
44    }
45};