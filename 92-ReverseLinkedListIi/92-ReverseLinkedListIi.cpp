// Last updated: 3/18/2026, 3:01:32 PM
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* start = dummy;

        for(int i = 1; i < left; i++) {
            start = start -> next;
        }

        ListNode* curr = start -> next;
        ListNode* prev = NULL;

        for(int i = 0; i <= right - left; i++) {
            ListNode* nxt = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nxt;

        }

        start -> next -> next = curr;
        start -> next = prev;

        return dummy -> next;
    }
};