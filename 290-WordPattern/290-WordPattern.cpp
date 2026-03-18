// Last updated: 3/18/2026, 2:28:16 PM
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;

        vector<string> words;
        string temp = "";

        for (char c : s) {
            if (c == ' ') {
                words.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }
        words.push_back(temp); 

        if (pattern.size() != words.size())
            return false;

        for (int i = 0; i < pattern.size(); i++) {
            char p = pattern[i];
            string w = words[i];

            if (mp1.count(p) && mp1[p] != w)
                return false;

            if (mp2.count(w) && mp2[w] != p)
                return false;

            mp1[p] = w;
            mp2[w] = p;
        }

        return true;
    }
};
