// Last updated: 3/18/2026, 3:03:17 PM
class Solution {
public:
    bool isPalindrome(int t) {
        int x = t;
        if (x < 0) return false;
        if(x == 0) return true;
        
        long long y = 0;
        int r = 0;
        while(x != 0){
            
            r = x % 10;
            y = 10*y + r;
            x /= 10;
        }
       
        if(t == y) return true;
        else return false;
    }
};