// Last updated: 6/25/2026, 4:05:23 PM
1class Solution {
2public:
3    vector<int> dailyTemperatures(vector<int>& temperatures) {
4        int n = temperatures.size();
5        vector<int> r(n, 0);
6        stack<int> st;
7
8        for(int i = n - 1; i >= 0; i--) {
9            while(!st.empty() && temperatures[st.top()] <= temperatures[i]) {
10                st.pop();
11            }
12
13            if(!st.empty()) {
14                r[i] = st.top() - i;
15            }
16            st.push(i);
17        }
18        return r;
19    }
20};