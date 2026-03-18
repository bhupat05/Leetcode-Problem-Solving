// Last updated: 3/18/2026, 3:01:43 PM
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
    // Helper: Insert at tail
    void insert(ListNode*& head, int val) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
            return;
        }
        ListNode* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        // Step 1: collect unique values in a set
        set<int> s;
        ListNode* temp = head;
        while (temp) {
            s.insert(temp->val);
            temp = temp->next;
        }

        // Step 2: build a new list from set elements
        ListNode* newHead = nullptr;
        for (int val : s) {
            insert(newHead, val);
        }

        return newHead;
    }
};
