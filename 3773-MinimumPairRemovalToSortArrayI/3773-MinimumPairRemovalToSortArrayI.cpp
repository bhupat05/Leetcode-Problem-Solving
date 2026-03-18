// Last updated: 3/18/2026, 2:20:42 PM
class Solution {
public:
    bool dec(const vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int r = 0;

        while (!dec(nums)) {

            priority_queue<
                pair<int,int>,
                vector<pair<int,int>>,
                greater<pair<int,int>>
            > mh;

            for (int i = 0; i + 1 < nums.size(); i++) {
                mh.push({nums[i] + nums[i + 1], i});
            }

            auto [sum, idx] = mh.top();

            nums[idx] = sum;
            nums.erase(nums.begin() + idx + 1);

            r++;
        }

        return r;
    }
};
