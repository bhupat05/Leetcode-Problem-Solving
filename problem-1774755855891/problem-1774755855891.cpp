// Last updated: 3/29/2026, 9:14:15 AM
1class Solution {
2public:
3    bool solve(vector<int>& v) {
4        int n = v.size();
5        int x = 0;
6
7        for(int i = 1; i < n; i++) {
8            if(v[i] < v[i - 1]) x++;
9        }
10
11        if(v[0] < v[n - 1]) x++;
12
13        return x <= 1;
14    }
15
16    bool check(vector<int>& v) {
17        int n = v.size();
18
19        for(int i = 1; i < n; i++) {
20            if(v[i] < v[i - 1]) return false;
21        }
22        return true;
23    }
24
25    int sortableIntegers(vector<int>& nums) {
26        int n = nums.size();
27        unordered_set<int> st;
28
29        for(int i = 1; i <= n; i++) {
30            if(n % i == 0) {
31                st.insert(i);
32            }
33        }
34
35        int sum = 0;
36
37        if(check(nums)) {
38            for(int x : st) sum += x;
39            return sum;
40        }
41
42        st.erase(1);
43
44        for(int x : st) {
45            bool flag = true;
46            int prev_max = -1;
47
48            for(int i = 0; i < n; i += x) {
49                vector<int> v(nums.begin() + i, nums.begin() + i + x);
50
51                if(!solve(v)) {
52                    flag = false;
53                    break;
54                }
55
56                int c_min = *min_element(v.begin(), v.end());
57                int c_max = *max_element(v.begin(), v.end());
58
59                if(prev_max > c_min) {
60                    flag = false;
61                    break;
62                }
63
64                prev_max = c_max;
65            }
66            
67            if(flag) sum += x;
68        }
69
70        return sum;
71    }
72};