// Last updated: 9/14/2026, 12:47:21 AM
1class FreqStack {
2public:
3    unordered_map<int,int> mp;
4    vector<stack<int>> st;
5    int mx = 0;
6    FreqStack() : st(100005) {
7        
8    }
9    
10    void push(int val) {
11        mp[val]++;
12        mx = max(mx, mp[val]);
13
14        st[mp[val]].push(val);
15
16    }
17    
18    int pop() {
19        int val = st[mx].top();
20        st[mx].pop();
21        mp[val]--;
22        if(st[mx].empty()) mx--;
23        return val;
24    }
25};
26
27/**
28 * Your FreqStack object will be instantiated and called as such:
29 * FreqStack* obj = new FreqStack();
30 * obj->push(val);
31 * int param_2 = obj->pop();
32 */