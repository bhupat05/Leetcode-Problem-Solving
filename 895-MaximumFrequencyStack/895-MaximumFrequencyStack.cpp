// Last updated: 9/14/2026, 12:12:09 AM
1class FreqStack {
2public:
3    unordered_map<int,int> mp;
4   priority_queue<pair<pair<int,int>, int>> pq;
5    int cnt = 0;
6    FreqStack() {
7        
8    }
9    
10    void push(int val) {
11        mp[val]++;
12        pq.push({{mp[val], cnt++}, val});
13    }
14    
15    int pop() {
16        auto p = pq.top();
17        pq.pop();
18
19        int val = p.second;
20        mp[val]--;
21        return val;
22    }
23};
24
25/**
26 * Your FreqStack object will be instantiated and called as such:
27 * FreqStack* obj = new FreqStack();
28 * obj->push(val);
29 * int param_2 = obj->pop();
30 */