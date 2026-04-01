// Last updated: 4/1/2026, 10:05:14 AM
1class Solution {
2public:
3    vector<int> survivedRobotsHealths(vector<int>& a, vector<int>& b, string c) {
4        int n = a.size();
5        vector<int> result(n, 0);
6
7        unordered_map<int, int> mp;
8
9        for(int i = 0; i < n; i++) {
10            mp[a[i]] = i;
11        }
12
13        vector<pair<int, pair<int, char>>> v;
14
15        for (int i = 0; i < n; i++) {
16            v.push_back({a[i], {b[i], c[i]}});
17        }
18
19        sort(v.begin(), v.end());
20
21        vector<int> st; 
22
23        for(int i = 0; i < n; i++) {
24            if(v[i].second.second == 'R') {
25                st.push_back(i);  
26            } 
27            else {
28                while(!st.empty() && v[i].second.first > 0) {
29                    int j = st.back();
30
31                    if(v[j].second.first < v[i].second.first) {
32                        st.pop_back();
33                        v[i].second.first--;
34                        v[j].second.first = 0;
35                    }
36                    else if(v[j].second.first == v[i].second.first) {
37                        st.pop_back();
38                        v[i].second.first = 0;
39                        v[j].second.first = 0;
40                        break;
41                    }
42                    else {
43                        v[j].second.first--;
44                        v[i].second.first = 0;
45                        break;
46                    }
47                }
48            }
49        }
50
51        for(int i = 0; i < n; i++) {
52            if(v[i].second.first > 0) {
53                result[mp[v[i].first]] = v[i].second.first;
54            }
55        }
56
57        vector<int> ans;
58        for(int i = 0; i < n; i++) {
59            if(result[i] > 0) ans.push_back(result[i]);
60        }
61
62        return ans;
63    }
64};