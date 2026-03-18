// Last updated: 3/18/2026, 2:25:22 PM
class Solution {
public:
    int GCD(int a, int b) {
        while(b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 != str2 + str1) return "";

        int g = GCD(str1.length(), str2.length());
        return str2.substr(0, g);
    }
};