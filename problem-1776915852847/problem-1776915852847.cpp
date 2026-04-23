// Last updated: 4/23/2026, 9:14:12 AM
1class Solution {
2public:
3    vector<long long> distance(vector<int>& nums) {
4        int n = nums.size();
5        unordered_map<int, vector<int>> mp;
6        vector<long long> res(n);
7
8        for(int i = 0; i < n; i++) {
9            mp[nums[i]].push_back(i);
10        }
11
12        for(auto &it : mp) {
13            vector<int> &v = it.second;
14            int k = v.size();
15
16            vector<long long> prefix(k);
17            prefix[0] = v[0];
18
19            for(int i = 1; i < k; i++) {
20                prefix[i] = prefix[i - 1] + v[i];
21            }
22
23            for(int i = 0; i < k; i++) {
24                long long ans = 0;
25
26                if(i > 0)
27                    ans += (long long)v[i] * i - prefix[i - 1];
28
29                if(i < k - 1)
30                    ans += (prefix[k - 1] - prefix[i]) - (long long)v[i] * (k - i - 1);
31
32                res[v[i]] = ans;
33            }
34        }
35
36        return res;
37    }
38};