// Last updated: 9/1/2026, 8:55:44 AM
1class Solution {
2public:
3    int countSpecialIntegers(vector<int>& nums) {
4        int n = nums.size();
5        unordered_map<int, vector<int>> mp;
6        int ans = 0;
7
8        for(int i = 0; i < n; i++) {
9            mp[nums[i]].push_back(i);
10        }
11
12        for(auto [x, v] : mp) {
13            bool f = false;
14            for(int i = 1; i < v.size(); i++) {
15                if(v[i] != v[i - 1] + 1) {
16                    f = true;
17                    break;
18                }
19            }
20            if(!f) ans++;
21        }
22        return ans;
23    }
24};