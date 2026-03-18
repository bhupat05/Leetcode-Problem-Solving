// Last updated: 3/18/2026, 2:19:56 PM
class Solution {
public:
    long long minMoves(vector<int>& balance) {
        int n = balance.size();
        
        long long sum = 0;
        int pivot = -1;

        for(int i = 0; i < n; i++) {
            sum += balance[i];
            if(balance[i] < 0) pivot = i;
        }

        if(pivot == -1) return 0;
        if(sum < 0) return -1;

        long long cnt = 0;
        long long t = -balance[pivot];

        for(int d = 1; t > 0; d++) {
            
            int l = (pivot - d + n) % n;
            int r = (pivot + d) % n;

            if(balance[l] > 0) {
                
                long long x = min((long long)balance[l], t);
                balance[l] -= x;
                t -= x;
                cnt += x * d;
            }

            if(t > 0 && l != r && balance[r] > 0) {
                
                long long x = min((long long)balance[r], t);
                balance[r] -= x;
                t -= x;
                cnt += x * d;
            }
        }
        
        return cnt;
    }
};
