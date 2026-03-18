// Last updated: 3/18/2026, 3:03:10 PM
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";  

        string s = "";
        int minLength = INT_MAX;

        for (const string& word : strs) {
            minLength = min(minLength, (int)word.size());
        }

        for (int i = 0; i < minLength; i++) {
            char currentChar = strs[0][i];
            for (const string& word : strs) {
                if (word[i] != currentChar) {
                    return s;  
                }
            }
            
            s += currentChar;
        }

        return s;  
    }
};
