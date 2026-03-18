// Last updated: 3/18/2026, 2:19:02 PM
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long cnt = 0;
        int l = 0;

        deque<int> maxdq, mindq;

        for (int i = 0; i < n; i++) {

            while (!maxdq.empty() && maxdq.back() < nums[i])
                maxdq.pop_back();
            maxdq.push_back(nums[i]);

            while (!mindq.empty() && mindq.back() > nums[i])
                mindq.pop_back();
            mindq.push_back(nums[i]);

            long long cost =
                (long long)(maxdq.front() - mindq.front()) * (i - l + 1);

            while (cost > k && l <= i) {
                if (maxdq.front() == nums[l]) maxdq.pop_front();
                if (mindq.front() == nums[l]) mindq.pop_front();
                l++;

                cost = (long long)(maxdq.front() - mindq.front()) * (i - l + 1);
            }

            cnt += (i - l + 1);
        }

        return cnt;
    }
};
