// Muhammed Orhun Gale - lcs.h - 14/05/2024
#ifndef LCS_H
#define LCS_H

#include <string>
#include <vector>
#include <stack>
#include <tuple>
#include "trie.h"

class LCS {
private:
    std::vector<std::vector<int>> dp;
    std::string seq1;
    std::string seq2;
    void fillDP();
    Trie trie;

public:
    LCS(std::string seq_1, std::string  seq_2);
    std::vector<std::string> getLCS();
    int getLCSLength() const;
};

#endif