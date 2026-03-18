// Last updated: 3/18/2026, 2:24:39 PM
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, set<int>> mp;

        for(auto &s : reservedSeats) {
            mp[s[0]].insert(s[1]);
        }

        int result = (n - mp.size()) * 2;

        for(auto &[row, seats] : mp) {
            bool left = true, mid = true, right = true;

            for(int s : seats) {
                if(s >= 2 && s <= 5) left = false;
                if(s >= 4 && s <= 7) mid = false;
                if(s >= 6 && s <= 9) right = false;
            }

            if(left) result++;
            if(right) result++;
            if(!left && !right && mid) result++;
        }

        return result;
    }
};