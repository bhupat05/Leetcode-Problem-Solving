// Last updated: 3/18/2026, 3:03:00 PM
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
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;

        if(l1 -> val < l2 -> val) {
            l1 ->next = merge(l1 -> next, l2);
            return l1;
        } else {
            l2 -> next = merge(l1, l2 -> next);
            return l2;
        }
        return NULL;
    }
    ListNode* pMerge(int l, int r, vector<ListNode*>& lists) {
        if(l == r) return lists[l];
        if(l > r) return NULL;

        int mid = l + (r - l) / 2;

        ListNode* l1 = pMerge(l, mid, lists);
        ListNode* l2 = pMerge(mid + 1, r, lists);
        return merge(l1, l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k == 0) return NULL;

        return pMerge(0, k - 1, lists);
    }
};