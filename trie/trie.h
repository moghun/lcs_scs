// Muhammed Orhun Gale - trie.h - 14/05/2024
#ifndef TRIE_H
#define TRIE_H

#include <vector>
#include <memory>
#include <iostream>

struct TrieNode {
public:
    static const int ALPHABET_SIZE = 127 - 32;

    std::vector<std::shared_ptr<TrieNode>> children;
    bool isEndOfWord;

    TrieNode() : children(ALPHABET_SIZE, nullptr), isEndOfWord(false) {}
};

class Trie {
private:
    std::shared_ptr<TrieNode> root;
public:
    Trie() : root(std::make_shared<TrieNode>()) {}

    void insert(const std::string &key);
    bool search(const std::string &key);
    std::vector<std::string> getKeysWithGivenLength(const int length);
};

#endif
