// Last updated: 3/18/2026, 2:27:32 PM
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        int count = 0;
        int i = 0, j = 1;

        while(j < n){
            vector<int> curr = intervals[i];
            vector<int> next = intervals[j];

            int cs = curr[0];
            int ce = curr[1];

            int ns = next[0];
            int ne = next[1];

            if(ce <= ns){
                i = j;
                j++;
            }else if(ce <= ne){
                j++;
                count++;
            }else if(ce > ne){
                i = j;
                j++;
                count++;
            }
        }
        return count;
    }
};