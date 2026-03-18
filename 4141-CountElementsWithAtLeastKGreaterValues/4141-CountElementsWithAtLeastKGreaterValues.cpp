// Last updated: 3/18/2026, 2:19:27 PM
class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int x = 0;

        if(k == 0) return n;

        sort(nums.rbegin(), nums.rend());

        for(int i = 1; i < n ; i++) {
            if(nums[i] < nums[i -1]) {
                x = i;
            }
            if(x >= k) {
                count = n - i;
                break;
            }
        }
        return count;
    }
};