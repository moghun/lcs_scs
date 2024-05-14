// Muhammed Orhun Gale - scs.h - 14/05/2024
#ifndef SCS_H
#define SCS_H

#include "lcs.h"  // Including the LCS class header
#include <string>

class SCS {
private:
    std::string seq1;
    std::string seq2;
    LCS lcsCalculator;

public:
    SCS(const std::string& seq_1, const std::string& seq_2);
    std::string getSCS();
};

#endif
