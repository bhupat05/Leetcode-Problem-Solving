// Last updated: 3/18/2026, 2:25:06 PM
class Solution {
public:

    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        vector<int> v(26, 0);
        for (int i = 0; i < s.size(); i++) {
            v[s[i] - 'a']++;
            v[t[i] - 'a']--;
        }

        for (int count : v) {
            if (count != 0) return false;
        }
        return true;
    }

    vector<string> removeAnagrams(vector<string>& words) {
        int i = 1;
        while (i < words.size()) {
            if (isAnagram(words[i - 1], words[i])) {
                words.erase(words.begin() + i);
            } else {
                i++;
            }
        }
        return words;
    }
};
