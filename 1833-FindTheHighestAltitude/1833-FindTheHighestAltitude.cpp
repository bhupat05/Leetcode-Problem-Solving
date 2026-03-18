// Last updated: 3/18/2026, 2:23:54 PM
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();

        int result = 0;
        int altitude = 0;

        for(int i = 0; i < n; i++) {
            altitude = altitude + gain[i];
            result = max(result, altitude);
        }
        return result;
        
    }
};