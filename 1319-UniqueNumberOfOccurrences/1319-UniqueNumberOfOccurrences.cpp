// Last updated: 3/18/2026, 2:25:09 PM
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int offset = 1000;
        int count[2001] = {0};
        for (int num : arr) count[num + offset]++;

        bool seen[1001] = {0};
        for (int c : count) {
            if (c == 0) continue;
            if (seen[c]) return false;
            seen[c] = true;
        }
        return true;
    }
};
