// Last updated: 3/18/2026, 2:29:40 PM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return nullptr;

        ListNode *a = headA;
        ListNode *b = headB;
        while(a != b){
            a = (a == nullptr)?headB:a = a->next;
            b = (b == nullptr)?headA:b = b->next;
        }
        return a;
    }
};