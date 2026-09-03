// Last updated: 9/3/2026, 3:05:07 PM
1class Solution {
2public:
3    bool valid( unordered_map<int, int>& mp,  unordered_map<int, int>& freq) {
4        if(mp.size() == 1) return true;
5        if(freq.size() != 2) return false;
6
7        auto it = freq.begin();
8        int a = it -> first;
9        ++it;
10        int b = it -> first;
11        if(a < b) swap(a, b);
12        return a == 2 * b;
13    }
14    int getLength(vector<int>& nums) {
15        int n = nums.size();
16        int ans = 1;
17
18        for(int i = 0; i < n; i++) {
19            unordered_map<int, int> mp;
20            unordered_map<int, int> freq;
21            for(int j = i; j < n; j++) {
22                int x = nums[j];
23                int cnt = mp[x];
24                if(cnt > 0) {
25                    freq[cnt]--;
26                }
27                if(freq[cnt] == 0) {
28                    freq.erase(cnt);
29                }
30                mp[x]++;
31                freq[mp[x]]++;
32
33                if(valid(mp, freq)) {
34                    ans = max(ans, j - i + 1);
35                }
36            }
37        }
38        return ans;
39    }
40};