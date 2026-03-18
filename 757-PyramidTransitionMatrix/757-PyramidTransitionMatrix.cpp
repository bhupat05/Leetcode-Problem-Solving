// Last updated: 3/18/2026, 2:26:28 PM
class Solution {
public:
    unordered_map<string, vector<char>> mp;
    unordered_map<string, bool> memo;

    bool dfs(string &bottom) {
        if (bottom.size() == 1) return true;
        if (memo.count(bottom)) return memo[bottom];

        bool res = buildNext(bottom, 0, "");
        memo[bottom] = res;
        return res;
    }

    bool buildNext(string &bottom, int idx, string curr) {
        if (idx == bottom.size() - 1)
            return dfs(curr);

        string key = bottom.substr(idx, 2);
        if (!mp.count(key)) return false;

        for (char c : mp[key]) {
            if (buildNext(bottom, idx + 1, curr + c))
                return true;
        }
        return false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (string &t : allowed)
            mp[t.substr(0, 2)].push_back(t[2]);

        return dfs(bottom);
    }
};
