// Last updated: 3/18/2026, 2:21:13 PM
class Solution {
public:
    long long sum = 0;
    set<pair<int, int>> mainSet;   // renamed “main” (reserved in C++)
    set<pair<int, int>> sec;
    int x; // store x globally so insert/remove can access it

    void insertInSet(pair<int, int> p) {
        if ((int)mainSet.size() < x || p > *mainSet.begin()) {
            sum += 1LL * p.first * p.second;
            mainSet.insert(p);

            if ((int)mainSet.size() > x) {
                auto smallest = *mainSet.begin();
                sum -= 1LL * smallest.first * smallest.second;
                mainSet.erase(smallest);
                sec.insert(smallest);
            }
        } else {
            sec.insert(p);
        }
    }

    void removeFromSet(pair<int, int> p) {
        if (mainSet.find(p) != mainSet.end()) {
            sum -= 1LL * p.first * p.second;
            mainSet.erase(p);

            if (!sec.empty()) {
                auto largest = *sec.rbegin();
                sec.erase(prev(sec.end()));

                mainSet.insert(largest);
                sum += 1LL * largest.first * largest.second;
            }
        } else if (sec.find(p) != sec.end()) {
            sec.erase(p);
        }
    }

    vector<long long> findXSum(vector<int>& nums, int k, int X) {
        int n = nums.size();
        x = X; // set global x
        sum = 0;

        vector<long long> result;
        unordered_map<int, int> mp;

        int i = 0, j = 0;

        while (j < n) {
            if (mp[nums[j]] > 0) {
                removeFromSet({mp[nums[j]], nums[j]});
            }

            mp[nums[j]]++;
            insertInSet({mp[nums[j]], nums[j]});

            if (j - i + 1 == k) {
                result.push_back(sum);

                removeFromSet({mp[nums[i]], nums[i]});
                mp[nums[i]]--;
                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                } else {
                    insertInSet({mp[nums[i]], nums[i]});
                }
                i++;
            }
            j++;
        }
        return result;
    }
};
