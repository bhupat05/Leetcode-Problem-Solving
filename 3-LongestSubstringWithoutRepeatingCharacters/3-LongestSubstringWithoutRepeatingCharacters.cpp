// Last updated: 3/18/2026, 3:03:26 PM
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0;
        int maxi = 0;
        vector<int> v(256, 0); 

        for (int i = 0; i < n; i++) {
            v[s[i]]++;

            while (v[s[i]] > 1) {
                v[s[l]]--;
                l++;
            }

            maxi = max(maxi, i - l + 1);
        }

        return maxi;
    }
};
