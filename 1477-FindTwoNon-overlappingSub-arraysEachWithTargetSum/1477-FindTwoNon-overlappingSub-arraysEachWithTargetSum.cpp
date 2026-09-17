// Last updated: 9/17/2026, 9:11:58 PM
1class Solution {
2public:
3    int minSumOfLengths(vector<int>& arr, int target) {
4        int n = arr.size();
5        // [3, 2, 1, 4, 3] t = 3
6        unordered_map<int, int> mp;
7        mp[0] = -1;
8        int sum = 0;
9        int ans = n + 1;
10        int mn = n;
11        for(int i = 0; i < n; i++) {
12            sum += arr[i];
13            if(mp.count(sum - target)) {
14                int l = mp[sum - target];
15                int len = i - l;
16                ans = min(ans, len + (l == -1 ? n : arr[l]));
17                mn = min(mn, len);
18            }
19            arr[i] = mn;
20            mp[sum] = i;
21        }
22        return ans == n + 1 ? -1 : ans;
23    }
24};