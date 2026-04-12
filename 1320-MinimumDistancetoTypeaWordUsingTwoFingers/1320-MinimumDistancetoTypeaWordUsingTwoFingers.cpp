// Last updated: 4/12/2026, 10:19:15 AM
1class Solution {
2public:
3    vector<pair<int,int>> pos;
4    int dp[301][27][27]; // i, f1, f2
5
6    int dist(int a, int b) {
7        if(a == -1) return 0;
8        return abs(pos[a].first - pos[b].first) +
9               abs(pos[a].second - pos[b].second);
10    }
11
12    int solve(string &word, int f1, int f2, int i) {
13        if(i >= word.size()) return 0;
14
15        int &res = dp[i][f1 + 1][f2 + 1]; 
16        if(res != -1) return res;
17
18        int curr = word[i] - 'A';
19
20        int a = dist(f1, curr) + solve(word, curr, f2, i + 1);
21        int b = dist(f2, curr) + solve(word, f1, curr, i + 1);
22
23        return res = min(a, b);
24    }
25
26    int minimumDistance(string word) {
27        pos.resize(26);
28        for(int i = 0; i < 26; i++) {
29            pos[i] = {i / 6, i % 6};
30        }
31
32        memset(dp, -1, sizeof(dp));
33
34        return solve(word, -1, -1, 0);
35    }
36};