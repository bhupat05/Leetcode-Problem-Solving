// Last updated: 3/18/2026, 2:27:22 PM
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if(points.empty()) return 0;
        sort(points.begin(), points.end());
        vector<int> pre = points[0];
        int count = 1;

        for(int i = 1; i < n; i++){
            
            int currstart = points[i][0];
            int currend = points[i][1];

            int prestart = pre[0];
            int preend = pre[1];

            if(currstart > preend){
                count++;
                pre = points[i];
            }else{
                pre[0] = max(prestart, currstart);
                pre[1] = min(currend, preend);
            }

        }

        
        
        return count;
    }
};