#include "Trie.h"

// TrieNode constructor
TrieNode::TrieNode(char data) : data(data), end(false) {
    for (int i = 0; i < 26; i++) {
        children[i] = nullptr;
    }
}

// Trie constructor
Trie::Trie() : root(new TrieNode('\0')) {}

// Insert word utility
void Trie::insertUtil(TrieNode* root, const std::string& word) {
    if (word.empty()) {
        root->end = true;
        return;
    }
    int index = word[0] - 'a';
    if (!root->children[index]) {
        root->children[index] = new TrieNode(word[0]);
    }
    insertUtil(root->children[index], word.substr(1));
}

// Insert a word
void Trie::insertWord(const std::string& word) {
    insertUtil(root, word);
}

// Search utility
bool Trie::searchUtil(TrieNode* root, const std::string& word) {
    if (word.empty()) return root->end;
    int index = word[0] - 'a';
    if (!root->children[index]) return false;
    return searchUtil(root->children[index], word.substr(1));
}

// Search for a word
bool Trie::searchWord(const std::string& word) {
    return searchUtil(root, word);
}

// DFS for collecting all words
void Trie::dfs(TrieNode* node, std::string& prefix, std::vector<std::string>& result) {
    if (node->end) result.push_back(prefix);
    for (int i = 0; i < 26; i++) {
        if (node->children[i]) {
            prefix.push_back('a' + i);
            dfs(node->children[i], prefix, result);
            prefix.pop_back();
        }
    }
}

// Get all strings stored in the Trie
std::vector<std::string> Trie::getAllStrings() {
    std::vector<std::string> result;
    std::string prefix = "";
    dfs(root, prefix, result);
    return result;
}

// Suggest words using Jaccard similarity
std::string Trie::suggestWord(const std::vector<std::string>& strings, const std::string& target) {
    std::vector<std::pair<std::string, double>> matches;

    for (const std::string& s : strings) {
        int intersection = 0, union_size = 0;
        std::unordered_map<char, int> freq1, freq2;

        for (char c : target) freq1[c]++;
        for (char c : s) freq2[c]++;

        for (auto& [ch, count] : freq1) {
            if (freq2.find(ch) != freq2.end()) {
                intersection += std::min(count, freq2[ch]);
            }
            union_size += count;
        }
        for (auto& [ch, count] : freq2) union_size += count;

        matches.emplace_back(s, (double)intersection / union_size);
    }

    std::sort(matches.begin(), matches.end(), [](const auto& lhs, const auto& rhs) {
        return lhs.second > rhs.second;
    });

    return matches.empty() ? target : matches.front().first;
}

// Print all words stored in the Trie
void Trie::printAllWords() {
    std::vector<std::string> allWords = getAllStrings();
    for (const std::string& word : allWords) {
        std::cout << word << std::endl;
    }
}
