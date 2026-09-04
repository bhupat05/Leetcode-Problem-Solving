// Last updated: 9/4/2026, 9:43:23 AM
1class Solution {
2public:
3    vector<string> ans;
4    void solve(int n, int k, int idx, string &temp, bool can, int cost) {
5        if(idx == n && cost <= k) {
6            ans.push_back(temp);
7            return;
8        }
9        if(cost > k) return;
10        if(can) {
11            temp.push_back('0');
12            solve(n, k, idx + 1, temp, true, cost);
13            temp.pop_back();
14            temp.push_back('1');
15            solve(n, k, idx + 1, temp, false, cost + idx);
16            temp.pop_back();
17        } else {
18            temp.push_back('0');
19            solve(n, k, idx + 1, temp, true, cost);
20            temp.pop_back();
21        }
22    }
23    vector<string> generateValidStrings(int n, int k) {
24        string temp = "";
25        solve(n, k, 0, temp, true, 0);
26        return ans;
27    }
28};