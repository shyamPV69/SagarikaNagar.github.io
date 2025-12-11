#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    bool endOfWord;
    TrieNode* children[26];

    TrieNode() {
        endOfWord = false;
        for (int i = 0; i < 26; i++) children[i] = nullptr;
    }
};

struct Trie {
    TrieNode* root;
    Trie() { root = new TrieNode(); }

    void insert(const string &word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!isalpha(c)) continue; // ignore non-letters for simplicity
            c = tolower(c);
            int index = c - 'a';
            if (!node->children[index])
                node->children[index] = new TrieNode();
            node = node->children[index];
        }
        node->endOfWord = true;
    }

    void collectWords(TrieNode* node, string current, vector<string> &result) {
        if (!node) return;
        if (node->endOfWord) result.push_back(current);
        for (int i = 0; i < 26; i++) {
            if (node->children[i]) {
                char c = 'a' + i;
                collectWords(node->children[i], current + c, result);
            }
        }
    }

    vector<string> autocomplete(const string &prefix) {
        TrieNode* node = root;
        string cleanPrefix;
        for (char c : prefix) {
            if (!isalpha(c)) continue;
            c = tolower(c);
            int index = c - 'a';
            if (!node->children[index]) return {};
            node = node->children[index];
            cleanPrefix.push_back(c);
        }
        vector<string> result;
        collectWords(node, cleanPrefix, result);
        return result;
    }
};

int main() {
    Trie trie;
    // Some place names (simplified: only letters)
    trie.insert("sagarikamall");
    trie.insert("sagarikatechpark");
    trie.insert("seaviewhospital");
    trie.insert("centralmarket");

    string prefix;
    cout << "Enter prefix: ";
    cin >> prefix;

    auto suggestions = trie.autocomplete(prefix);
    cout << "Suggestions:\n";
    for (auto &s : suggestions) cout << s << "\n";

    return 0;
}
