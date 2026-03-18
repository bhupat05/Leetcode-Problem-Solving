// Last updated: 3/18/2026, 2:21:31 PM
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long sum = 0;   
        sort(happiness.rbegin(), happiness.rend());

        int cnt = 0;
        for (int x : happiness) {
            if (k == 0 || x - cnt <= 0) break;

            sum += (x - cnt);
            cnt++;
            k--;
        }
        return sum;
    }
};
