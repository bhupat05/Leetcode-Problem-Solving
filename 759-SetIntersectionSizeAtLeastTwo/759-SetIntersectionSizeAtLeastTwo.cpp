// Last updated: 3/18/2026, 2:26:27 PM
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
            [](const vector<int>& a, const vector<int>& b) {
                if (a[1] == b[1]) return a[0] > b[0];
                return a[1] < b[1];
            });

        int a = -1, b = -1; 
        int count = 0;

        for (auto &in : intervals) {
            int l = in[0], r = in[1];

            bool hasA = (a >= l && a <= r);
            bool hasB = (b >= l && b <= r);

            if (hasA && hasB) {
                continue;
            } 
            else if (hasB) {
                ++count;
                a = b;
                b = r;
            } 
            else {
                count += 2;
                a = r - 1;
                b = r;
            }
        }
        return count;
    }
};
