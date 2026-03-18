// Last updated: 3/18/2026, 2:27:49 PM
class RandomizedSet {
public:
    vector<int>v;
    unordered_map<int, int> mp;   
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.count(val)) return false;

        v.push_back(val);
        mp[val] = v.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(!mp.count(val)) return false;

        int idx = mp[val];
        int x = v.back();
        v[idx] = x;
        mp[x] = idx;
        v.pop_back();
        mp.erase(val); 
        return true;
    }
    
    int getRandom() {
        int idx = rand() % (v.size());
        return v[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */