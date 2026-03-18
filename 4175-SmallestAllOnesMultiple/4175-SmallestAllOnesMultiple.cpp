// Last updated: 3/18/2026, 2:19:11 PM
class Solution {
public:
    int gcd(int a, int b) {
        if(b == 0) return a;
        return gcd(b, a % b);
    }
    
   
    int minAllOneMultiple(int k) {

        if(gcd(k, 10) != 1) return -1;
        
        int r = 0;
        
        for(int i = 1; i <= k; i++) {
            r = (r * 10 + 1) % k;
            if(r == 0) {
                return i;
            }
        }
        return -1;
    }
};