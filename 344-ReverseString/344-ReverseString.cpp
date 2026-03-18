// Last updated: 3/18/2026, 2:27:59 PM
class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0;
        int r = s.size() -1;

        while(l <= r){
            swap(s[l],s[r]);
            l++;
            r--;
        }
    }
};