// Last updated: 3/18/2026, 2:25:41 PM
class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> map;
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        const auto& v = map[key];
        int l = 0, r = v.size() - 1, res = -1;

        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(v[mid].first > timestamp) {
                r = mid - 1;
            } else {
                res = mid;
                l = mid + 1;
            }
        }

        return res == -1 ? "" : v[res].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */