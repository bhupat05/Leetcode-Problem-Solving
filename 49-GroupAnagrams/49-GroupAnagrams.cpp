// Last updated: 3/18/2026, 3:02:27 PM
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;


        for(string &str : strs) {
            string x = str;
            sort(x.begin(), x.end());
            mp[x].push_back(str);
        }   

        vector<vector<string>> result;

        for(auto &it : mp) {
            result.push_back(it.second);
        }
        return result;
    }
};