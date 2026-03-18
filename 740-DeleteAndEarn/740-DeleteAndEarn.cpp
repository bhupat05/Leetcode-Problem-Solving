// Last updated: 3/18/2026, 2:26:35 PM
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());

        vector<int> points(maxi + 1, 0);

        for(int x : nums) {
            points[x] += x;
        }

        int a = 0;
        int b = points[0];

        for(int i = 1; i <= maxi; i++) {
            int c = max(b, a + points[i]);
            a = b;
            b = c;
        }
        return b;
    }
};