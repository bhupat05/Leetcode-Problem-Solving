// Last updated: 3/18/2026, 2:24:57 PM
struct TrieNode {
    TrieNode* children[26];
    bool isEnd;
    vector<string> suggestions;

    TrieNode() {
        isEnd = false;
        for(int i = 0; i < 26; i++) 
            children[i] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string &word) {
        TrieNode* node = root;

        for(char c : word) {
            int idx = c - 'a';

            if(node->children[idx] == nullptr)
                node->children[idx] = new TrieNode();

            node = node->children[idx];

            if(node->suggestions.size() < 3)
                node->suggestions.push_back(word);
        }
        node->isEnd = true;
    }

    vector<vector<string>> getSuggestions(string &searchWord) {
        vector<vector<string>> result;
        TrieNode* node = root;

        for(char c : searchWord) {
            int idx = c - 'a';

            if(node != nullptr)
                node = node->children[idx];  

            if(node == nullptr)
                result.push_back({});       
            else
                result.push_back(node->suggestions);
        }

        return result;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {

        sort(products.begin(), products.end()); 

        Trie trie;

        for(string &product : products)
            trie.insert(product);

        return trie.getSuggestions(searchWord);
    }
};
