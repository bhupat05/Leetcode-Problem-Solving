// Last updated: 3/18/2026, 2:29:20 PM
class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while(n > 0){
            if(n & 1) count++;
            n >>= 1;
        }
        return count;
    }
};