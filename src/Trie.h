#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

class TrieNode {
public:
    char data;
    bool end;
    TrieNode* children[26];

    TrieNode(char data);
};

class Trie {
private:
    TrieNode* root;

    void insertUtil(TrieNode* root, const std::string& word);
    bool searchUtil(TrieNode* root, const std::string& word);
    void dfs(TrieNode* node, std::string& prefix, std::vector<std::string>& result);

public:
    Trie();
    void insertWord(const std::string& word);
    bool searchWord(const std::string& word);
    void printAllWords();
    std::vector<std::string> getAllStrings();
    std::string suggestWord(const std::vector<std::string>& strings, const std::string& target);
};

#endif
