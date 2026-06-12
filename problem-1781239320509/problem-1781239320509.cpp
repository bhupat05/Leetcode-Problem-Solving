// Last updated: 6/12/2026, 10:12:00 AM
1class Solution {
2public:
3    bool uniqueOccurrences(vector<int>& arr) {
4        int n = arr.size();
5        unordered_map<int, int> mp;
6        unordered_set<int> st;
7
8        for(int x : arr) {
9            mp[x]++;
10        }
11        for(auto  x : mp) {
12            if(st.count(x.second)) {
13                return false;
14            }
15            st.insert(x.second);
16        }
17        return true;
18    }
19};