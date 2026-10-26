// Last updated: 10/26/2026, 12:40:33 PM
1class Solution {
2    int gcd(int a, int b) {
3        return b == 0 ? a : gcd(b, a % b);
4    }
5    public String gcdOfStrings(String str1, String str2) {
6        if(!((str1 + str2).equals(str2 + str1))) return "";
7
8        int len = gcd(str1.length(), str2.length());
9        return str1.substring(0, len);
10    }
11}