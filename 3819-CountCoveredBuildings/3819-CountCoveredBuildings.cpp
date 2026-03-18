// Last updated: 3/18/2026, 2:20:35 PM
class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, vector<pair<int,int>>> mpx;
        unordered_map<int, vector<pair<int,int>>> mpy;

        // Build maps
        for (auto &it : buildings) {
            int x = it[0];
            int y = it[1];
            mpx[x].push_back({x, y});
            mpy[y].push_back({x, y});
        }

        for (auto &it : mpx) {
            auto &v = it.second;
            sort(v.begin(), v.end(),
                [](const auto &a, const auto &b) {
                    return a.second < b.second;
                });
        }

        for (auto &it : mpy) {
            auto &v = it.second;
            sort(v.begin(), v.end(),
                [](const auto &a, const auto &b) {
                    return a.first < b.first;
                });
        }

        int count = 0;

        for (auto &it : buildings) {
            int x = it[0];
            int y = it[1];

            int a = mpx[x].size();
            int b = mpy[y].size();

            auto &firstX = mpx[x][0];
            auto &lastX  = mpx[x][a-1];

            auto &firstY = mpy[y][0];
            auto &lastY  = mpy[y][b-1];

            bool isFirstX = (x == firstX.first && y == firstX.second);
            bool isLastX  = (x == lastX.first  && y == lastX.second);

            bool isFirstY = (x == firstY.first && y == firstY.second);
            bool isLastY  = (x == lastY.first  && y == lastY.second);

            if (isFirstX || isLastX || isFirstY || isLastY)
                continue;

            if (a > 2 && b > 2)
                count++;
        }

        return count;
    }
};
