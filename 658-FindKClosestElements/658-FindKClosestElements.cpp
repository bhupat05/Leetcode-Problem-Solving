// Last updated: 9/5/2026, 11:49:45 PM
1class Solution {
2public:
3    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
4        int n = arr.size();
5        int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
6        // cout << n << " " << idx << endl;
7        
8       
9
10        vector<int> ans;
11        
12        
13        if(idx >= n) {
14            idx = n - 1;
15        }
16
17        int l = idx-1; 
18        int r = idx;
19        // ans.push_back(arr[idx]);
20
21        while(l >= 0 && r < n && k) {
22            int a = abs(arr[l] - x);
23            int b = abs(arr[r] - x);
24            if(a <= b) {
25                ans.push_back(arr[l]);
26                l--;
27                // cout << ans.back() << "a "; 2 3 10 x = 5; >= 5
28            } else {
29                ans.push_back(arr[r]);
30                r++;
31                // cout << ans.back() << " b";
32                
33            }
34            k--;
35        }
36        while(k && l >= 0) {
37            ans.push_back(arr[l]);
38            l--;
39            k--;
40        }
41        while(k && r < n) {
42            ans.push_back(arr[r]);
43            r++;
44            k--;
45
46        }
47        sort(ans.begin(), ans.end());
48        return ans;
49    }
50};