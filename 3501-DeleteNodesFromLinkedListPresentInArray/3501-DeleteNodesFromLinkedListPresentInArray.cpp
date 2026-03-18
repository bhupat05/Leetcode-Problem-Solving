// Last updated: 3/18/2026, 2:21:15 PM
class Solution 
{
public:
    ListNode* modifiedList(std::vector<int>& nums, ListNode* head) 
    {
        unordered_set<int> numSet(nums.begin(), nums.end());

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* curr = dummy;

        while (curr->next) {
            
            if (numSet.count(curr->next->val)) {
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};