// Last updated: 3/18/2026, 2:20:05 PM
class Solution {
public:
    bool isValid(string t) {
        if (t.empty()) return false;

        for(char c : t) {
            bool f = (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || 
            (c >= '0' && c <= '9') || (c == '_');  

            if(!f) return false;
        }
        return true;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {

        int n = code.size();
        unordered_map<string, vector<string>>mp;
        vector<string> result;
        vector<string> order = {
            "electronics",
            "grocery",
            "pharmacy",
            "restaurant"
        };

        for(int i = 0; i < n; i++) {
            bool f = businessLine[i] == "electronics" || businessLine[i] == "grocery" || 
            businessLine[i] == "pharmacy" || businessLine[i] == "restaurant";

            if(f && isActive[i]) {
                mp[businessLine[i]].push_back(code[i]);
            }
        }

        for(auto & p : mp) {
            sort(p.second.begin(), p.second.end());
        }

        for(string s : order) {
            if(mp.count(s)) {
                for(string t : mp[s]) {

                    if(isValid(t))
                    result.push_back(t);
                }
            }
        }
        return result;

    }
};