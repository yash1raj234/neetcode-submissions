class Solution {
public:
struct TrieNode {
        TrieNode* children[26];
        string word;
        TrieNode() { 
            for (int i = 0; i < 26; i++) children[i] = nullptr; 
            word = "";
        }
    };

    void insert(TrieNode* root, string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->word = word;
    }
       void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, vector<string>& result) {
        char c = board[i][j];
        if (c == '#' || !node->children[c - 'a']) return;
        node = node->children[c - 'a'];
        if (node->word != "") {
            result.push_back(node->word);
            node->word = ""; // avoid duplicates
        }

        board[i][j] = '#';
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        for (auto& d : dirs) {
            int x = i + d[0], y = j + d[1];
            if (x >= 0 && y >= 0 && x < board.size() && y < board[0].size()) {
                dfs(board, x, y, node, result);
            }
        }
        board[i][j] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (auto& word : words) insert(root, word);

        vector<string> result;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, result);
            }
        }
        return result;
    }
};
