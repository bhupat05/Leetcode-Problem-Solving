// Last updated: 8/15/2026, 10:48:41 PM
1class Solution {
2public:
3    bool solve(vector<int> v, string s, int i, int j) {
4        for(int k = i; k < j; k++) {
5            v[s[k] - 'a']--;
6        }
7        for(int i = 0; i < 26; i++) {
8            if(v[i] > 0) return false;
9        }
10
11        return true;
12    }
13    bool checkInclusion(string s1, string s2) {
14        int m = s1.size();
15        vector<int> v(26, 0);
16
17        for(char c : s1) {
18            v[c - 'a']++;
19        }   
20
21        for(int i = 0; i + m <= s2.size(); i++) {
22            if(solve(v, s2, i, i + m)) return true;
23        }
24        return false;
25    }
26};