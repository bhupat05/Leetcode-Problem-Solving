// Last updated: 7/8/2026, 6:43:10 PM
1/*
2// Definition for a Node.
3class Node {
4public:
5    int val;
6    vector<Node*> neighbors;
7    Node() {
8        val = 0;
9        neighbors = vector<Node*>();
10    }
11    Node(int _val) {
12        val = _val;
13        neighbors = vector<Node*>();
14    }
15    Node(int _val, vector<Node*> _neighbors) {
16        val = _val;
17        neighbors = _neighbors;
18    }
19};
20*/
21
22class Solution {
23public:
24    unordered_map<Node*, Node*> mp;
25    Node* cloneGraph(Node* node) {
26        if(!node) return nullptr;
27
28        if(mp.count(node)) return mp[node];
29
30        Node* clone = new Node(node -> val);
31        mp[node] = clone;
32
33        for(auto nbr : node -> neighbors) {
34            (clone -> neighbors).push_back(cloneGraph(nbr));
35        }
36        return clone;
37    }
38};
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56