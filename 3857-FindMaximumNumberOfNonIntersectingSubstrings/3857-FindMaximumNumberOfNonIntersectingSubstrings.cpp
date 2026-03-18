// Last updated: 3/18/2026, 2:20:25 PM
class Solution {
public:
    int maxSubstrings(string word) {
        int n = word.length();
        vector<vector<int>> intervals;

        
        for (int i = 0; i < n; i++) {
            for (int j = i + 3; j < n; j++) { 
                if (word[i] == word[j]) {
                    intervals.push_back({i, j});
                    break; 
                }
            }
        }

        
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1]; 
        });

        
        int count = 0, last_end = -1;
        for (const auto& interval : intervals) {
            if (interval[0] > last_end) {
                count++;
                last_end = interval[1];
            }
        }

        return count;
    }
};
