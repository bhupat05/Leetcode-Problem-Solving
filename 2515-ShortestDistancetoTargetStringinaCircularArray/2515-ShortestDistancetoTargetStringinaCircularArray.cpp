// Last updated: 4/15/2026, 10:03:43 AM
1class Solution {
2public:
3    int closestTarget(vector<string>& words, string target, int idx) {
4        int n = words.size();   
5        int i = idx, j = idx;
6        
7        for(int cnt = 0; cnt < n; cnt++) {
8            if(words[i] == target || words[j] == target) {
9                return cnt;
10            }
11            
12            i = (i + 1) % n;             
13            j = (j - 1 + n) % n;          
14        }
15        
16        return -1;
17    }
18};