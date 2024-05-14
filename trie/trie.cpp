// Muhammed Orhun Gale - trie.cpp - 14/05/2024
#include "trie.h"
#include <iostream>
#include "trie.h"

// Function to insert a key into the Trie
void Trie::insert(const std::string &key) {
    std::shared_ptr<TrieNode> node = root;
    for (char ch : key) {
        int index = ch - 32;
        if (index < 0 || index >= TrieNode::ALPHABET_SIZE) {
            std::cerr << "Error: Invalid character '" << ch << "' in key." << std::endl;
            continue;  // Skip invalid characters
        }
        if (!node->children[index]) {
            node->children[index] = std::make_shared<TrieNode>();
        }
        node = node->children[index];
    }
    node->isEndOfWord = true;
}

// Function to search for a key in the Trie
bool Trie::search(const std::string &key) {
    std::shared_ptr<TrieNode> node = root;
    for (char ch : key) {
        int index = ch - 32;
        if (index < 0 || index >= TrieNode::ALPHABET_SIZE) {
            std::cerr << "Error: Invalid character '" << ch << "' in key." << std::endl;
            return false;
        }
        if (!node->children[index]) {
            return false;
        }
        node = node->children[index];
    }
    return node->isEndOfWord;
}

// Helper function to recursively collect keys with a given length
void collectKeys(const std::shared_ptr<TrieNode>& node, int length, std::string currentString, std::vector<std::string>& results) {
    if (!node) return;

    if (length == 0) {
        if (node->isEndOfWord) {
            results.push_back(currentString);
        }
        return;
    }

    for (int i = 0; i < TrieNode::ALPHABET_SIZE; ++i) {
        if (node->children[i]) {
            char nextChar = static_cast<char>(i + 32);
            collectKeys(node->children[i], length - 1, currentString + nextChar, results);
        }
    }
}


// Function to get all keys of a given length
std::vector<std::string> Trie::getKeysWithGivenLength(int length) {
    std::vector<std::string> results;
    collectKeys(root, length, "", results);
    return results;
}

