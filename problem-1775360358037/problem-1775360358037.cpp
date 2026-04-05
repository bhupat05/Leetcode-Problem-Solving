// Last updated: 4/5/2026, 9:09:18 AM
1class Solution {
2public:
3    vector<int> findGoodIntegers(int n) {
4        vector<int> result;
5        unordered_set<int> st;
6        unordered_set<int> st2;
7
8        
9
10        for(int i = 1; i <= 1000; i++) {
11            for(int j = i; j <= 1000; j++) {
12                int x = (i * i * i) + (j * j * j);
13                if(x <= n) {
14                    if(st.count(x)) {
15                        // result.push_back(x);
16                        st2.insert(x);
17                        // st.erase(x);
18                    } 
19                
20                    st.insert(x);
21                }
22               
23                
24            }
25        }
26        for(auto it : st2) {
27            result.push_back(it);
28        }
29        sort(result.begin(), result.end());
30        return result;
31    }
32};