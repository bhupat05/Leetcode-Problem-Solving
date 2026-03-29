// Last updated: 3/29/2026, 8:27:28 AM
1class EventManager {
2public:
3    unordered_map<int, int> mp;
4    priority_queue<pair<int, int>> pq;
5
6    EventManager(vector<vector<int>>& events) {
7        for(auto &it : events) {
8            mp[it[0]] = it[1];
9            pq.push({it[1], -it[0]}); 
10        }
11    } 
12    
13    void updatePriority(int eventId, int newPriority) {
14        mp[eventId] = newPriority;
15        pq.push({newPriority, -eventId}); 
16    }
17    
18    int pollHighest() {
19        while(!pq.empty()) {
20            auto top = pq.top();
21            int priority = top.first;
22            int id = -top.second;
23
24            if(mp.count(id) && mp[id] == priority) {
25                pq.pop();
26                mp.erase(id); 
27                return id;
28            }
29            pq.pop(); 
30        }
31        return -1;
32    }
33};