// Last updated: 3/18/2026, 2:28:28 PM
class Solution {
public:
    bool isUgly(int n) {
        if(n <=0) return false;

        vector<int>prime = {2,3,5};

        for(int p : prime){
            while(n % p == 0){
                n /= p;
            }
        }
        return n == 1;
    }
};