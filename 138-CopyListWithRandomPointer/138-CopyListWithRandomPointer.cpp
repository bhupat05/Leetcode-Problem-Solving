// Last updated: 3/18/2026, 2:30:03 PM
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }

        unordered_map<Node*, Node*> mp;

        Node* curr = head;

        while (curr != nullptr) {
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;
        while (curr != nullptr) {
            mp[curr]->next = (curr->next != nullptr) ? mp[curr->next] : nullptr;
            mp[curr]->random = (curr->random != nullptr) ? mp[curr->random] : nullptr;
            curr = curr->next;
        }

        return mp[head];
    }
};
