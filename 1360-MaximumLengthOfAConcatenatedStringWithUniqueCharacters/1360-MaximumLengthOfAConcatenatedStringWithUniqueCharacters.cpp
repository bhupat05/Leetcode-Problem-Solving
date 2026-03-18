// Last updated: 3/18/2026, 2:25:05 PM
class Solution {
public:
    // Helper to check if combining s1 and s2 would result in duplicate characters
    bool hd(string &s1, string &s2) {
        int arr[26] = {0};

        // Check characters in s1
        for (char &ch : s1) {
            if (arr[ch - 'a'] > 0) return true; // <-- bug fixed here
            arr[ch - 'a']++;
        }

        // Check characters in s2
        for (char &ch : s2) {
            if (arr[ch - 'a'] > 0) return true; // <-- bug fixed here
            arr[ch - 'a']++;
        }

        return false; // means s1 and s2 have no common characters
    }

    // Backtracking solve function
    int solve(int i, vector<string> &arr, string temp, int n) {
        if (i >= n) return temp.length();

        int include = 0, exclude = 0;

        // Check if we can include arr[i]
        if (!hd(temp, arr[i])) {
            include = solve(i + 1, arr, temp + arr[i], n);
        }

        exclude = solve(i + 1, arr, temp, n);

        return max(include, exclude);
    }

    int maxLength(vector<string> &arr) {
        return solve(0, arr, "", arr.size());
    }
};
