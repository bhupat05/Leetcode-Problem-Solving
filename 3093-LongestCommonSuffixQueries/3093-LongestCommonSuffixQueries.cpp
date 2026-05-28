// Last updated: 5/28/2026, 9:28:40 PM
1class Trie {
2public:
3    Trie() : tot_(0) {
4        for (int i = 0; i < N; i++) {
5            memset(tr_[i], 0, sizeof(tr_[i]));
6            min_len_[i] = INT_MAX;
7            idx_[i] = INT_MAX;
8        }
9    }
10    void clear() {
11        for (int i = 0; i <= tot_; i++) {
12            memset(tr_[i], 0, sizeof(tr_[i]));
13            min_len_[i] = INT_MAX;
14            idx_[i] = INT_MAX;
15        }
16        tot_ = 0;
17    }
18    void insert(const string& s, int idx) {
19        int p = 0;
20        if (min_len_[p] > s.length()) {
21            min_len_[p] = s.length();
22            idx_[p] = idx;
23        }
24        for (auto& ch : s) {
25            int c = ch - 'a';
26            if (tr_[p][c] == 0) {
27                tr_[p][c] = ++tot_;
28            }
29            p = tr_[p][c];
30            if (min_len_[p] > s.length()) {
31                min_len_[p] = s.length();
32                idx_[p] = idx;
33            }
34        }
35    }
36    int query(const string& s) {
37        int p = 0;
38        for (auto& ch : s) {
39            int c = ch - 'a';
40            if (tr_[p][c] != 0) {
41                p = tr_[p][c];
42            } else {
43                break;
44            }
45        }
46        return idx_[p];
47    }
48
49private:
50    static constexpr int N = 500010, M = 26;
51    int tot_;
52    int tr_[N][M];
53    int min_len_[N];
54    int idx_[N];
55};
56
57Trie tr;
58
59class Solution {
60public:
61    vector<int> stringIndices(vector<string>& wordsContainer,
62                              vector<string>& wordsQuery) {
63        tr.clear();
64        int n = wordsContainer.size();
65        int m = wordsQuery.size();
66        for (int i = 0; i < n; i++) {
67            string s = wordsContainer[i];
68            reverse(s.begin(), s.end());
69            tr.insert(s, i);
70        }
71
72        vector<int> res(m);
73        for (int i = 0; i < m; i++) {
74            string s = wordsQuery[i];
75            reverse(s.begin(), s.end());
76            res[i] = tr.query(s);
77        }
78        return res;
79    }
80};