// Muhammed Orhun Gale - lcs.cpp - 14/05/2024
#include "lcs.h"
#include <iostream>

// Constructor initializing sequences and the DP matrix
LCS::LCS(std::string seq_1, std::string seq_2) : dp(seq_1.length() + 1, std::vector<int>(seq_2.length() + 1, 0)), seq1(seq_1), seq2(seq_2) {
    fillDP();  // Fill the DP table right after initialization
}

// Fills the dp array to find the length of the longest common subsequence
void LCS::fillDP() {
    for (size_t i = 1; i <= seq1.length(); i++) {
        for (size_t j = 1; j <= seq2.length(); j++) {
            if (seq1[i - 1] == seq2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
}

// Returns the length of the longest common subsequence
int LCS::getLCSLength() const {
    return dp[seq1.length()][seq2.length()];
}

// Other existing methods...

void LCS::printAllLCS(std::vector<std::string> &lcsList) {
    if (lcsList.empty()) {
        std::cout << "No LCS available." << std::endl;
        return;
    }
    std::cout << "All Longest Common Subsequences:" << std::endl;
    for (const auto& lcs : lcsList) {
        std::cout << lcs << std::endl;
    }
}


// Generates all LCS using a backtracking stack approach, inserting them into a Trie for unique collection
std::vector<std::string> LCS::getLCS() {
    if (seq1.empty() || seq2.empty()) {
        std::cerr << "Error: One or both sequences are empty." << std::endl;
        return {};  // Return an empty vector if either sequence is empty
    }

    int i = seq1.length(), j = seq2.length();
    std::stack<std::tuple<int, int, std::string>> stack;
    stack.push({i, j, ""});

    while (!stack.empty()) {
        auto [ci, cj, currentLCS] = stack.top();
        stack.pop();

        if (ci == 0 || cj == 0) {
            if (!currentLCS.empty()) {
                trie.insert(currentLCS);
            }
        } else {
            if (seq1[ci - 1] == seq2[cj - 1]) {
                stack.push({ci - 1, cj - 1, seq1[ci - 1] + currentLCS});
            } else {
                if (ci > 0 && dp[ci - 1][cj] >= dp[ci][cj - 1]) {
                    stack.push({ci - 1, cj, currentLCS});
                }
                if (cj > 0 && dp[ci][cj - 1] >= dp[ci - 1][cj]) {
                    stack.push({ci, cj - 1, currentLCS});
                }
            }
        }
    }


    return trie.getKeysWithGivenLength(getLCSLength());
}