// Last updated: 3/18/2026, 2:21:51 PM
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> vec = nums;
        sort(vec.begin(), vec.end());

        int groupnum = 0;
        
        unordered_map<int, int> numToGroup;
        numToGroup[vec[0]] = groupnum;

        unordered_map<int, list<int>> groupToList;
        groupToList[groupnum].push_back(vec[0]);

        for (int i = 1; i < n; i++) {  // Start from index 1 to avoid accessing -1 index
            if (abs(vec[i] - vec[i - 1]) > limit) {
                groupnum += 1;
            }
            numToGroup[vec[i]] = groupnum;
            groupToList[groupnum].push_back(vec[i]);
        }

        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int group = numToGroup[num];
            result[i] = groupToList[group].front();
            groupToList[group].pop_front();
        }
        return result;
    }
};
