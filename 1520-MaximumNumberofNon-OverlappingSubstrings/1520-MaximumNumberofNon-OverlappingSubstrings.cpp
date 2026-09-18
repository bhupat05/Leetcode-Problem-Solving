// Last updated: 9/18/2026, 10:39:16 PM
1class Solution {
2public:
3    struct Seg {
4        int left, right;
5        bool operator<(const Seg& rhs) const {
6            if (right == rhs.right) {
7                return left > rhs.left;
8            }
9            return right < rhs.right;
10        }
11    };
12
13    vector<string> maxNumOfSubstrings(string s) {
14        vector<Seg> seg(26, (Seg){-1, -1});
15        // Preprocess the left and right endpoints.
16        for (int i = 0; i < s.length(); ++i) {
17            int charIdx = s[i] - 'a';
18            if (seg[charIdx].left == -1) {
19                seg[charIdx].left = seg[charIdx].right = i;
20            } else {
21                seg[charIdx].right = i;
22            }
23        }
24        for (int i = 0; i < 26; ++i) {
25            if (seg[i].left != -1) {
26                for (int j = seg[i].left; j <= seg[i].right; ++j) {
27                    int charIdx = s[j] - 'a';
28                    if (seg[i].left <= seg[charIdx].left &&
29                        seg[charIdx].right <= seg[i].right) {
30                        continue;
31                    }
32                    seg[i].left = min(seg[i].left, seg[charIdx].left);
33                    seg[i].right = max(seg[i].right, seg[charIdx].right);
34                    j = seg[i].left;
35                }
36            }
37        }
38        // Greedily select intervals.
39        sort(seg.begin(), seg.end());
40        vector<string> ans;
41        int end = -1;
42        for (auto& segment : seg) {
43            int left = segment.left, right = segment.right;
44            if (left == -1) {
45                continue;
46            }
47            if (end == -1 || left > end) {
48                end = right;
49                ans.emplace_back(s.substr(left, right - left + 1));
50            }
51        }
52        return ans;
53    }
54};