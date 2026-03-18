// Last updated: 3/18/2026, 3:01:37 PM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummySmall = new ListNode(0);
        ListNode* dummyBig = new ListNode(0);

        ListNode* small = dummySmall;
        ListNode* big = dummyBig;

        while(head) {
            if(head -> val < x) {
                small -> next = head;
                small = small -> next;
            } else {
                big -> next = head;
                big = big -> next;
            }
            head = head -> next;
        }

        big -> next = NULL;
        small -> next = dummyBig -> next;

        return dummySmall -> next;

    }
};