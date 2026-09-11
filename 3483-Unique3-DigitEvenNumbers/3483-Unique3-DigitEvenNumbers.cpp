// Last updated: 9/11/2026, 10:24:47 AM
1class Solution {
2public:
3    int  cnt = 0;
4    int n;
5    unordered_set<int> st;
6    void solve(vector<int>& digits, vector<int> temp, vector<int>& path) {
7        if(!temp.empty() && temp[0] == 0) return;
8        if(temp.size() == 3) {
9            int x = 100 * temp[0] + 10 * temp[1] + temp[2];
10            if(!(x & 1) && !st.count(x)) {
11                cnt++;
12                st.insert(x);
13            }
14            return;
15        }
16        for(int i = 0; i < n; i++) {
17            if(path[i]) continue;
18            path[i] = 1; 
19            temp.push_back(digits[i]);
20            solve(digits, temp, path);
21            temp.pop_back();
22            path[i] = 0;
23        }
24    }
25    int totalNumbers(vector<int>& digits) {
26        n = digits.size();
27        vector<int> temp;
28        vector<int> path(10, 0);
29        solve(digits, temp, path);
30        return cnt;
31    }
32};