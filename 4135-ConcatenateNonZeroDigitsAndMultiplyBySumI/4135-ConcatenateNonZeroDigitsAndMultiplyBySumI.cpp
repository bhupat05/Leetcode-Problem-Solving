// Last updated: 3/18/2026, 2:19:32 PM
class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;

        string r = to_string(n);

       
        int sz = r.size();
         int l = r.size() - 1;

        for(int i = sz - 1; i >= 0; i--) {
            if(r[i] != '0') {
                swap(r[l] , r[i]);
                l--;
            }
        }

        x = stoi(r);
        long long t = x;
        int sum = 0;

        while(t > 0) {
            sum += t % 10;
            t /= 10;
        }

        return x * sum;

        
    }
};