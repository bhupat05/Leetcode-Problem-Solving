// Last updated: 3/18/2026, 2:20:45 PM
class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {

        double area = 0;                
        double minY = 1e18;
        double maxY = -1e18;

        for (auto &it : squares) {
            double l = it[2];            
            area += l * l;
            minY = min(minY, (double)it[1]);
            maxY = max(maxY, it[1] + l); 
        }

        double half = area / 2.0;        

        for (int i = 0; i < 60; i++) {
            double mid = minY + (maxY - minY) / 2.0;
            double below = 0;

            for (auto &it : squares) {
                double bottom = it[1];
                double l = it[2];
                double top = bottom + l;

                if (mid <= bottom) {
                    continue;
                }
                else if (mid >= top) {
                    below += l * l;      
                }
                else {
                    below += (mid - bottom) * l; 
                }
            }

            if (below < half) {
                minY = mid;
            } else {
                maxY = mid;
            }
        }

        return minY;
    }
};
