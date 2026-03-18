// Last updated: 3/18/2026, 3:02:57 PM
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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head -> next) return head;

        ListNode* first = head;
        ListNode* second = head -> next;

        first -> next = swapPairs(second -> next);
        second -> next = first;

        return second;
    }
};