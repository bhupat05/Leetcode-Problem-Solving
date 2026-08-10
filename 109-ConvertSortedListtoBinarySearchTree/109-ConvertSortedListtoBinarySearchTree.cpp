// Last updated: 8/10/2026, 8:28:51 PM
1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11/**
12 * Definition for a binary tree node.
13 * struct TreeNode {
14 *     int val;
15 *     TreeNode *left;
16 *     TreeNode *right;
17 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
18 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
19 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
20 * };
21 */
22class Solution {
23public:
24    TreeNode* solve(ListNode* head) {
25        if(!head) return nullptr;
26        if(!head -> next) {
27            TreeNode* root = new TreeNode(head-> val);
28            return root;
29        }
30
31        ListNode* slow = head;
32        ListNode* fast = head;
33        ListNode* prev = nullptr;
34
35        while(fast && fast -> next) {
36            prev = slow;
37            slow = slow -> next;
38            fast = fast -> next -> next;
39        }
40
41        TreeNode* root = new TreeNode(slow -> val);
42        ListNode* nxt = slow -> next;
43        prev -> next  = nullptr;
44        root -> left = solve(head);
45        root -> right = solve(nxt);
46        return root;
47        
48    }
49    TreeNode* sortedListToBST(ListNode* head) {
50    
51        return solve(head);
52    }
53};