// Last updated: 3/18/2026, 2:30:31 PM
class Solution {
public:
    Node* getNext(Node* root) {
        while (root) {
            if (root->left) return root->left;
            if (root->right) return root->right;
            root = root->next;
        }
        return NULL;
    }

    Node* connect(Node* root) {
        if (!root) return NULL;

        if (root->left) {
            if (root->right)
                root->left->next = root->right;
            else
                root->left->next = getNext(root->next);
        }

        if (root->right) {
            root->right->next = getNext(root->next);
        }

        connect(root->right);
        connect(root->left);

        return root;
    }
};
