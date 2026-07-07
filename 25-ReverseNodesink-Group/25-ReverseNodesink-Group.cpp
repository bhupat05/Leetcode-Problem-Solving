// Last updated: 7/8/2026, 1:00:05 AM
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
11class Solution {
12public:
13    ListNode* reversell(ListNode* head){
14        if(head == NULL || head->next == NULL){
15            return head;
16        }
17
18        ListNode* last = reversell(head->next);
19        head->next->next = head;
20        head->next = NULL;
21        return last;
22    }
23    void reorderList(ListNode* head) {
24        ListNode* slow = head;
25        ListNode* fast = head;
26
27        while(fast && fast ->next){
28            slow = slow -> next;
29            fast = fast -> next -> next;
30        }
31
32        ListNode* rev = reversell(slow);
33        ListNode* curr = head;
34
35        while(rev -> next != NULL){
36            ListNode* tempcurr = curr -> next;
37            curr ->next = rev;
38
39            ListNode* temprev = rev -> next;
40            rev -> next = tempcurr;
41
42            curr = tempcurr;
43            rev = temprev;
44        }
45        
46    }
47};