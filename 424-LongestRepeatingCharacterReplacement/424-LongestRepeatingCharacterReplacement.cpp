// Last updated: 3/18/2026, 2:27:35 PM
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();

        int l = 0;
        int r = 0;
        int maxlen = 0, maxf = 0;
        vector<int>count(26, 0);

        while(r < n){
            count[s[r] - 'A']++;
            maxf = max(maxf, count[s[r] - 'A']);

            while((r - l + 1) - maxf > k){
                count[s[l] - 'A']--;
                l++;
            }

            maxlen = max(maxlen, r - l + 1);
            r++;
        }

        return maxlen;


    }
};