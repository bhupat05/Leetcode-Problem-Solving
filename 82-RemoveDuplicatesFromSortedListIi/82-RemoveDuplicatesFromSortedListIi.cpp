// Last updated: 3/18/2026, 3:01:44 PM
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;

        while (head != nullptr) {
            if (head->next != nullptr && head->val == head->next->val) {
                int val = head->val;

                while (head != nullptr && head->val == val) {
                    head = head->next;
                }

                prev->next = head;
            } else {
                prev = head;
                head = head->next;
            }
        }

        return dummy.next;
    }
};
