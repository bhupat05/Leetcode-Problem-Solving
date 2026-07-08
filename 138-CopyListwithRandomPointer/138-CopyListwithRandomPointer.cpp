// Last updated: 7/8/2026, 6:57:10 PM
1/*
2// Definition for a Node.
3class Node {
4public:
5    int val;
6    Node* next;
7    Node* random;
8    
9    Node(int _val) {
10        val = _val;
11        next = NULL;
12        random = NULL;
13    }
14};
15*/
16
17class Solution {
18public:
19    unordered_map<Node*, Node*> mp;
20    Node* copyRandomList(Node* head) {
21        if(!head) return nullptr;
22
23        if(mp.count(head)) return mp[head];
24
25        Node* clone = new Node(head -> val);
26        mp[head] = clone;
27
28        clone -> next = copyRandomList(head -> next);
29        clone -> random = copyRandomList(head -> random);
30
31        return clone;   
32    }
33};