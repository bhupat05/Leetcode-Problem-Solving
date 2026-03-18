// Last updated: 3/18/2026, 2:29:01 PM
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    struct TrieNode {
        bool isEnd;            
        string word;           
        TrieNode* next[26];    

        TrieNode() : isEnd(false), word("") {
            for (int i = 0; i < 26; ++i)
                next[i] = nullptr;
        }
    };

    TrieNode* buildTrie(const vector<string>& words) {
        TrieNode* root = new TrieNode();

        for (const string& w : words) {
            TrieNode* node = root;

            for (char c : w) {
                int index = c - 'a';
                if (node->next[index] == nullptr)
                    node->next[index] = new TrieNode();
                node = node->next[index];
            }

            node->isEnd = true; 
            node->word = w;     
        }

        return root;
    }

    void dfs(vector<vector<char>>& board, int i, int j,
                   TrieNode* node, vector<string>& foundWords) {

        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '#')
            return;

        char c = board[i][j];
        TrieNode* nextNode = node->next[c - 'a'];

        if (nextNode == nullptr)
            return;

        if (nextNode->isEnd) {
            foundWords.push_back(nextNode->word);
            nextNode->isEnd = false; 
        }

        board[i][j] = '#';

        dfs(board, i + 1, j, nextNode, foundWords);
        dfs(board, i - 1, j, nextNode, foundWords);
        dfs(board, i, j + 1, nextNode, foundWords);
        dfs(board, i, j - 1, nextNode, foundWords);

        board[i][j] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> foundWords;
        if (board.empty() || words.empty()) return foundWords;

        TrieNode* root = buildTrie(words); 

        int rows = board.size();
        int cols = board[0].size();

        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                dfs(board, i, j, root, foundWords);
            }
        }

        return foundWords;
    }
};
