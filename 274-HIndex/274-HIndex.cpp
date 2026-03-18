// Last updated: 3/18/2026, 2:28:24 PM
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());

        int l = 0;
        int r = n - 1;
        int ans = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            int h = n - mid;  

            if (citations[mid] >= h) {
                ans = h;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
