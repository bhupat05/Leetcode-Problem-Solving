// Last updated: 9/12/2026, 8:08:31 PM
1class Solution {
2public:
3    int countSpecialIntegers(vector<int>& nums) {
4        int n = nums.size();
5         unordered_map<int, vector<int>> mp;
6        for(int i = 0; i < n; i++) {
7            mp[nums[i]].push_back(i);
8        }
9        int cnt = 0;
10
11        for(auto it : mp) {
12            int x = it.first;
13            vector<int> v = it.second;
14            if(v.size() < 3) continue;
15            bool f = false;
16            for(int i = 2; i < v.size(); i++) {
17                if(v[i] - v[i - 1] != v[i - 1] - v[i - 2]) {
18                    f = true;
19                    break;
20                }
21            }
22            if(!f) cnt++;
23        }
24        return cnt;
25    }
26};