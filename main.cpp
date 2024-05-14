#include <iostream>
#include <string>
#include "lcs/lcs.h"
#include "scs/scs.h"

int main() {
    std::string seq1, seq2;
    int choice;

    while (true) {
        std::cout << "Select an operation:\n";
        std::cout << "1. Find Longest Common Subsequence (LCS)\n";
        std::cout << "2. Find Shortest Common Supersequence (SCS)\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice (1-3): ";
        std::cin >> choice;

        if (choice == 3) {
            break;  // Exit the loop and program
        }

        std::cout << "Enter the first sequence: ";
        std::cin >> seq1;
        std::cout << "Enter the second sequence: ";
        std::cin >> seq2;

        if (choice == 1) {
            LCS lcs(seq1, seq2);
            std::vector<std::string> lcsVec = lcs.getLCS();
            lcs.printAllLCS(lcsVec);
            std::cout << "Length of LCS: " << lcs.getLCSLength() << std::endl;
        } else if (choice == 2) {
            SCS scs(seq1, seq2);
            std::cout << "The Shortest Common Supersequence is: " << scs.getSCS() << std::endl;
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
        std::cout << "\n ---------------------------------- \n";
    }

    std::cout << "Program terminated." << std::endl;
    return 0;
}
