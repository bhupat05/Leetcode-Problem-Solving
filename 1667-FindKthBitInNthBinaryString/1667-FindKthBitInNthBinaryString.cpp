// Last updated: 3/18/2026, 2:24:10 PM
class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";

        for(int i = 1; i < n; i++) {
            string curr = "";
        
            for(int j = 0; j < s.size(); j++) {
                int x = s[j] - '0';
                x = 1 - x;
                curr += (x + '0');
            }
            
            reverse(curr.begin(), curr.end());
            
            s = s + "1" + curr;  
        }

        return s[k - 1];
    }
};