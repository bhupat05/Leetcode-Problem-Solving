// Last updated: 3/18/2026, 2:23:06 PM
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
    int pairSum(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode *prev = nullptr;
        ListNode *temp = slow;

        while(temp != NULL) {
            ListNode *nxt = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = nxt;
        }

        int maxi = INT_MIN;

        while(prev != NULL) {
            int sum = 0;

            sum += head -> val;
            sum += prev -> val;

            prev = prev -> next;
            head = head -> next;

            maxi = max(maxi, sum);
        }
        return maxi;
    }
};