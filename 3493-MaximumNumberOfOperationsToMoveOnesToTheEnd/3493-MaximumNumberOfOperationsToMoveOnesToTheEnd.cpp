// Last updated: 3/18/2026, 2:21:17 PM
class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
        long long total = 0;   
        long long count = 0; 
        long long last = -1;  

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                if(i > 0 && (i - 1 != last)) {
                    count += total; 
                }
                
                total++;
                last = i;
            }
        }
        if(s[n - 1] == '0') {
            count += total;
        }
        return count;
    }
};
