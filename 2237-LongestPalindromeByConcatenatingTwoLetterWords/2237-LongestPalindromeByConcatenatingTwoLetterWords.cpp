// Last updated: 3/18/2026, 2:23:04 PM
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;

        for (string& word : words) {
            mp[word]++;
        }

        bool cu = false;
        int result = 0;

        for (string& word : words) {
            string rev = word;
            reverse(rev.begin(), rev.end());

            if (word != rev) {
                if (mp[word] > 0 && mp[rev] > 0) {
                    mp[word]--;
                    mp[rev]--;
                    result += 4;
                }
            } else {
                if (mp[word] >= 2) {
                    mp[word] -= 2;
                    result += 4;
                } else if (mp[word] == 1 && cu == false) {
                    mp[word]--;
                    result += 2;
                    cu = true;
                }
            }
        }

        return result;
    }
};
