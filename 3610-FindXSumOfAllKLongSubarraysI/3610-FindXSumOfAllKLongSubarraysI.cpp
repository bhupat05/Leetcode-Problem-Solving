// Last updated: 3/18/2026, 2:21:10 PM
class Solution {
public:
    typedef pair<int, int> p;

    struct cmp {
        bool operator()(p& a, p& b) {
            // Sort by frequency desc, then value desc
            if (a.first == b.first)
                return a.second < b.second;
            return a.first < b.first;
        }
    };

    int findTopXsum(unordered_map<int, int>& mp, int x) {
        priority_queue<p, vector<p>, cmp> pq;

        for (auto &it : mp)
            pq.push({it.second, it.first});

        int sum = 0;
        int count = 0;
        while (!pq.empty() && count < x) {
            auto [freq, val] = pq.top();
            pq.pop();
            sum += freq * val;
            count++;
        }
        return sum;
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> result;
        int i = 0, j = 0;

        while (j < n) {
            mp[nums[j]]++;

            if (j - i + 1 == k) {
                result.push_back(findTopXsum(mp, x));

                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }
            j++;
        }
        return result;
    }
};
