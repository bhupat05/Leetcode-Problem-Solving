// Last updated: 3/18/2026, 2:19:18 PM
class Solution {
public:
    string rev(string s) {
        int l = 0, r = s.size() - 1;
        while(l < r) {
            swap(s[l], s[r]);
            l++;
            r--;
        }
        return s;
    }

    int vowel(string s) {
        int cnt = 0;
        for(char c : s) {
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                cnt++;
        }
        return cnt;
    }

    string reverseWords(string s) {
        vector<string> word;
        string t = "";

        for(char c : s) {
            if(c == ' ') {
                word.push_back(t);
                t.clear();
            } else {
                t += c;
            }
        }
        word.push_back(t); 

        int f = vowel(word[0]);

        string r = word[0];

        for(int i = 1; i < word.size(); i++) {
            string cur = word[i];
            if(vowel(cur) == f) {
                cur = rev(cur);
            }
            r += " " + cur;
        }

        return r;
    }
};
