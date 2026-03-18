// Last updated: 3/18/2026, 2:29:02 PM
struct TrieNode {
    TrieNode* children[26]; 
    bool isEnd;             

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class WordDictionary {
private:
    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index])
                node->children[index] = new TrieNode();
            node = node->children[index];
        }
        node->isEnd = true;
    }

    bool dfsSearch(string& word, int pos, TrieNode* node) {
        if (pos == word.size())
            return node->isEnd;

        char c = word[pos];

        if (c != '.') {
            int index = c - 'a';
            if (!node->children[index]) return false;
            return dfsSearch(word, pos + 1, node->children[index]);
        }

        for (int i = 0; i < 26; i++) {
            if (node->children[i] && dfsSearch(word, pos + 1, node->children[i]))
                return true;
        }

        return false;
    }

    bool search(string word) {
        return dfsSearch(word, 0, root);
    }
};


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */