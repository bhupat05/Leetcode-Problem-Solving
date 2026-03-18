// Last updated: 3/18/2026, 2:22:34 PM
class Solution {
public:
    int minimizeXor(int num1, int num2) {
        
        int b = __builtin_popcount(num2);

        int res = 0;

        for(int i=31; i>=0 && b>0; i--){
            if(num1 & (1 << i)){
                res |= (1<<i);
                b--;
            }
        }

        for(int i=0; i<32 && b>0; i++){
            if(!(res & (1<<i))){
                res |= (1<<i);
                b--;
            }
        }
        return res;
    }
};