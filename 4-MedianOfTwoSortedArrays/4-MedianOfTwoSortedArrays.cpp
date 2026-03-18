// Last updated: 3/18/2026, 3:03:24 PM
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> r(m + n);

        int i = 0;
        int j = 0;
        int k = 0;

        while(i < m && j < n) {
            if(nums1[i] < nums2[j]) {
                r[k++] = nums1[i++];
            } else {
                r[k++] = nums2[j++];
            }
        }

        while(i < m) {
            r[k++] = nums1[i++];
        }

        while(j < n) {
            r[k++] = nums2[j++];
        }

        if(r.size() == 0) return 0;
        if(r.size() == 1) return r[0];

        double result = -1;

        if((m + n) % 2 == 0) {
            result = r[(m + n - 2) / 2] / 2.0 + r[(m + n) / 2] / 2.0;
        } else {
            result = r[(m + n - 1) / 2];
        }
        return result;
    }
};