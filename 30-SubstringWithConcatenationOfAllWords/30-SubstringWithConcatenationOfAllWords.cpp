// Last updated: 3/18/2026, 3:02:48 PM
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> r;
        if (s.empty() || words.empty()) return r;

        int m = words.size();        
        int n = words[0].size();     
        int len = s.size();

        unordered_map<string, int> mp;
        for (auto &t : words) 
            mp[t]++;

        for (int i = 0; i < n; i++) {
            unordered_map<string, int> seen;
            int l = i;
            int cnt = 0;

            for (int j = i; j + n <= len; j += n) {
                string t = s.substr(j, n);

                if (mp.count(t)) {
                    seen[t]++;
                    cnt++;

                    while (seen[t] > mp[t]) {
                        string leftWord = s.substr(l, n);
                        seen[leftWord]--;
                        l += n;
                        cnt--;
                    }

                    if (cnt == m) {
                        r.push_back(l);
                    }
                } 
                else {
                    seen.clear();
                    cnt = 0;
                    l = j + n;
                }
            }
        }
        return r;
    }
};
