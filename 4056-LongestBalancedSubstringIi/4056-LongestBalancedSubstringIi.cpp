// Last updated: 3/18/2026, 2:19:49 PM
class Solution {
public:
    
    int solve(string &s, char c1, char c2, char skip) {
        int n = s.size();
        int maxLen = 0;

        for(int i = 0; i < n; ) {
            
            // skip unwanted character
            while(i < n && s[i] == skip) i++;
            if(i >= n) break;

            int start = i;

            while(i < n && s[i] != skip) i++;
            int end = i - 1;

            int x = 0, y = 0;
            unordered_map<int,int> mp;
            mp[0] = start - 1;

            for(int j = start; j <= end; j++) {
                if(s[j] == c1) x++;
                else if(s[j] == c2) y++;

                int diff = x - y;

                if(mp.count(diff)) {
                    maxLen = max(maxLen, j - mp[diff]);
                } else {
                    mp[diff] = j;
                }
            }
        }

        return maxLen;
    }

    int longestBalanced(string s) {
        int n = s.size();
        int mx = 1;

        // Case 1: single repeating
        int len = 1;
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i-1]) {
                len++;
                mx = max(mx, len);
            } else {
                len = 1;
            }
        }

        // Case 2: all three equal
        int a = 0, b = 0, c = 0;
        unordered_map<string,int> mp;
        mp["0,0"] = -1;

        for(int i = 0; i < n; i++) {
            if(s[i] == 'a') a++;
            else if(s[i] == 'b') b++;
            else c++;

            string key = to_string(a - b) + "," + to_string(a - c);

            if(mp.count(key)) {
                mx = max(mx, i - mp[key]);
            } else {
                mp[key] = i;
            }
        }


        mx = max(mx, solve(s, 'a', 'b', 'c'));
        mx = max(mx, solve(s, 'a', 'c', 'b'));
        mx = max(mx, solve(s, 'b', 'c', 'a'));

        return mx;
    }
};
