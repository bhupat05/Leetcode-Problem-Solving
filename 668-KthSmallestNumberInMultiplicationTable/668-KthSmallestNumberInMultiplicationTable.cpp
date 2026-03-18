// Last updated: 3/18/2026, 2:26:52 PM
class Solution {
public:
    
    int help(int m, int n, int mid) {
        int count = 0;
        for (int i = 1; i <= m; i++) {
            count += min(n, mid / i);  // In row i, how many numbers are <= mid
        }
        return count;
    }

    int findKthNumber(int m, int n, int k) {
        int low = 1, high = m * n, answer = -1;

        while (low <= high) {
            int mid = (low + high) / 2;

            int count = help(m, n, mid);

            if (count < k) {
                
                low = mid + 1;
            } else {
                
                answer = mid;
                high = mid - 1;
            }
        }

        return answer;
    }
};
