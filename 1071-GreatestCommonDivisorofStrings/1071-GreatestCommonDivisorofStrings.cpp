// Last updated: 6/10/2026, 8:22:41 AM
1class Solution {
2public:
3    int gcd(int a, int b) {
4        return b == 0 ? a : gcd(b, a % b);
5    }
6    string gcdOfStrings(string str1, string str2) {
7        if(str1 + str2 != str2 + str1) return "";
8        int g = gcd(str1.size(), str2.size());
9        return str1.substr(0, g);
10    }
11};