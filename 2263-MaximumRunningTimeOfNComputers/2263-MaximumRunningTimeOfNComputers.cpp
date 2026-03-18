// Last updated: 3/18/2026, 2:22:59 PM
class Solution {
public:
    using ll = long long;

    bool possible(vector<int>& batteries, ll mid_minutes, int n) {
        ll target_minutes = (ll)n * mid_minutes;
        ll sum = 0;

        for (int i = 0; i < batteries.size(); i++) {
            sum += min((ll)batteries[i], mid_minutes);
            if (sum >= target_minutes) return true;
        }
        return false;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        ll sum_total_minutes = 0;
        for (auto &it : batteries) sum_total_minutes += it;

        ll l = 0;
        ll r = sum_total_minutes / n;

        ll result = 0;

        while (l <= r) {
            ll mid_minutes = l + (r - l) / 2;

            if (possible(batteries, mid_minutes, n)) {
                result = mid_minutes;
                l = mid_minutes + 1;
            } else {
                r = mid_minutes - 1;
            }
        }
        return result;
    }
};
