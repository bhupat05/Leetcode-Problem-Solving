// Last updated: 6/10/2026, 9:13:29 AM
1class Solution {
2public:
3    string reverseVowels(string s) {
4        int n = s.size();
5        vector<int> v;
6
7        for(int i = 0; i < n; i++) {
8            if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || 
9               s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ) {
10                v.push_back(i);
11               }
12        }
13        int l = 0;
14        int r = v.size() - 1;
15        while(l <= r) {
16            swap(s[v[l]], s[v[r]]);
17            l++;
18            r--;
19        }
20        return s;
21    }
22};