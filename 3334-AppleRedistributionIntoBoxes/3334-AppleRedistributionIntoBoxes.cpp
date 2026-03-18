// Last updated: 3/18/2026, 2:21:34 PM
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = accumulate(apple.begin(), apple.end(), 0);

        sort(capacity.begin(), capacity.end(), greater<int>());

        int cnt = 0;
        for (int c : capacity) {
            sum -= c;
            cnt++;
            if (sum <= 0) return cnt;
        }

        return -1;
    }
};
