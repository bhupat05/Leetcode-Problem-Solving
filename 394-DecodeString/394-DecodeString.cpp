// Last updated: 6/27/2026, 10:47:24 PM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    int maxLevelSum(TreeNode* root) {
15        int maxSum = INT_MIN;
16        int resultLevel = 0;
17
18        queue<TreeNode*> que;
19        que.push(root);
20
21        int currLevel = 1;
22
23        while(!que.empty()) {
24            int n = que.size();
25            int sum = 0;
26
27            while(n--) {
28                TreeNode* temp = que.front();
29                que.pop();
30
31                sum += temp -> val;
32
33                if(temp -> left) {
34                    que.push(temp -> left);
35                }
36
37                if(temp -> right) {
38                    que.push(temp -> right);
39                }
40            }
41
42            if(sum > maxSum) {
43                maxSum = sum;
44                resultLevel = currLevel;
45            }
46            currLevel++;
47        }
48        return resultLevel;
49    }
50};