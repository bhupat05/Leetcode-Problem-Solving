// Last updated: 9/12/2026, 8:03:34 PM
1class Solution {
2public:
3    int countSpecialIntegers(vector<int>& nums) {
4        int n = nums.size();
5        unordered_map<int, vector<int>> mp;
6        for(int i = 0; i < n; i++) {
7            mp[nums[i]].push_back(i);
8        }
9        int cnt = 0;
10        for(auto it : mp) {
11            if(it.second.size() == 3) {
12                if(it.second[1] - it.second[0]  == it.second[2] - it.second[1]) cnt++;
13            }
14        }
15        return cnt;
16    }
17};