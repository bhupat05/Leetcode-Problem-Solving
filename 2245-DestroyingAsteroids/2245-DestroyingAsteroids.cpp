// Last updated: 3/18/2026, 2:23:03 PM
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int partIndex = 0;
        int previousPart = -1;
        unsigned long m = mass;

        while (true) {
            for (int i = partIndex; i < asteroids.size(); i++) {
                if (asteroids[i] <= m) {
                    m += asteroids[i];
                    swap(asteroids[partIndex], asteroids[i]);
                    partIndex++;
                }
            }
            if (partIndex == asteroids.size()) return true;
            if (partIndex == previousPart) return false;

            previousPart = partIndex;
        }

        return false;
    }
};