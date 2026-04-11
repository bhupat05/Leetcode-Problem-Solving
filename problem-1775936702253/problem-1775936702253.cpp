// Last updated: 4/12/2026, 1:15:02 AM
1class Solution {
2public:
3    char nextGreatestLetter(vector<char>& letters, char target) {
4        int l = 0;
5        int r = letters.size() - 1;
6
7        while(l < r) {
8            int mid = l + (r - l) / 2;
9
10            if(letters[mid] > target) {
11                r = mid;
12            } else {
13                l = mid + 1;
14            }
15        }
16        return letters[l] > target ? letters[l] : letters[0];
17    }
18};