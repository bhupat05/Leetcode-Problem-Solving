// Last updated: 4/13/2026, 12:53:16 AM
1class Solution {
2public:
3    char nextGreatestLetter(vector<char>& letters, char target) {
4        int idx = upper_bound(letters.begin(), letters.end(), target) - letters.begin();
5        
6        if(idx == letters.size()) return letters[0]; 
7        
8        return letters[idx];
9    }
10};