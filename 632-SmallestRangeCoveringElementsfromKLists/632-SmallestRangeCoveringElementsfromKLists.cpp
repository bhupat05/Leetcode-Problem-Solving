// Last updated: 9/8/2026, 1:31:54 AM
1class Solution {
2public:
3    vector<int> smallestRange(vector<vector<int>>& nums) {
4        int k = nums.size();
5        vector<pair<int, int>> arr;
6        for(int i = 0; i < k; i++) {
7            for(int x : nums[i]) {
8                arr.push_back({x, i});
9            }
10        }
11        sort(arr.begin(), arr.end());
12
13        vector<int> fre(k, 0);
14        int l = 0;
15        int req = 0;
16        int bl = -1e5;
17        int br = 1e5;
18
19        for(int i = 0; i < arr.size(); i++) {
20            auto[x, id] = arr[i];
21            if(fre[id] == 0) {
22                req++;
23            }
24            fre[id]++;
25
26            while(req == k) {
27                int cl = arr[l].first;
28                int cr = arr[i].first;
29                if(cr - cl < br - bl) {
30                    bl = cl;
31                    br = cr;
32                }
33                fre[arr[l].second]--;
34                if(fre[arr[l].second] == 0) req--;
35                l++;
36            }
37        }
38        return{bl, br};
39    }
40};