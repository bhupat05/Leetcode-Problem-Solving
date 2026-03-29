// Last updated: 3/29/2026, 1:35:52 PM
1class Solution {
2public:
3    Node* connect(Node* root) {
4        queue<Node*> q;
5
6        if(root) q.push(root);
7
8        while(!q.empty()){
9            int sz = q.size();
10
11            while(sz--){
12                Node* nd = q.front();
13                q.pop();
14
15                if(sz) nd->next = q.front();
16
17                if(nd->left) q.push(nd->left);
18                if(nd->right) q.push(nd->right);
19            }
20        }
21
22        return root;
23    }
24};