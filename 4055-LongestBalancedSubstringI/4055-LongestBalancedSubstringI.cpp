// Last updated: 3/18/2026, 2:19:51 PM
class Solution {
public:
    bool help(unordered_map<char, int>& mp) {
        int x = -1;
        for (auto &it : mp) {
            if (x == -1) {
                x = it.second;
            } else if (it.second != x) {  
                return false;
            }
        }
        return true;
    }

    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<char, int> mp;
            for (int j = i; j < n; j++) {    
                mp[s[j]]++;                  

                if (help(mp)) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};
