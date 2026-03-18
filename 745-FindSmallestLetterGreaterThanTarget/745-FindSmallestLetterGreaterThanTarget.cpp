// Last updated: 3/18/2026, 2:26:32 PM
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for(char c : letters) {
            if(c > target) return c;
        }
        return letters[0];
    }
};