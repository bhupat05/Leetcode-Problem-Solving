// Last updated: 3/18/2026, 2:27:07 PM
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();

        if(m > n) return false;

        vector<int> s1Freq(26, 0), windowFreq(26, 0);

        for(char c : s1) {
            s1Freq[c - 'a']++;
        }

        int l = 0;

        for(int i = 0; i < n; i++) {
            windowFreq[s2[i] - 'a']++;
            
            if(i - l + 1 > m) {
                windowFreq[s2[l] - 'a']--;
                l++;
            }

            if(windowFreq == s1Freq) return true;
        }
        return false;
    }
};