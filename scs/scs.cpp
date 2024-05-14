// Muhammed Orhun Gale - scs.cpp - 14/05/2024
#include "scs.h"

SCS::SCS(const std::string& seq_1, const std::string& seq_2) 
    : seq1(seq_1), seq2(seq_2), lcsCalculator(seq_1, seq_2) {}

std::string SCS::getSCS() {
    // First, get the LCS to use in SCS construction
    std::vector<std::string> lcsStrings = lcsCalculator.getLCS();
    if (lcsStrings.empty()) {
        return seq1 + seq2;  // If no common subsequence, concatenate
    }

    // Use the first LCS to build the SCS (for simplicity, assuming LCS returns non-empty)
    std::string lcs = lcsStrings.front();
    std::string scs = "";
    int i = 0, j = 0, k = 0;

    while (i < seq1.length() && j < seq2.length()) {
        // Walk through both sequences until you exhaust one
        while (i < seq1.length() && j < seq2.length() && (seq1[i] != lcs[k] || seq2[j] != lcs[k])) {
            if (seq1[i] != lcs[k])
                scs += seq1[i++];
            if (seq2[j] != lcs[k])
                scs += seq2[j++];
        }
        if (i < seq1.length() && j < seq2.length() && seq1[i] == lcs[k] && seq2[j] == lcs[k]) {
            scs += lcs[k++]; // Add the LCS char and move all pointers
            i++;
            j++;
        }
    }

    // Append remaining characters if any
    scs += seq1.substr(i) + seq2.substr(j);

    return scs;
}