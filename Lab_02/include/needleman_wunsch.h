#ifndef NEEDLEMAN_WUNSCH_H
#define NEEDLEMAN_WUNSCH_H

#include <string>
#include <vector>
#include <tuple>

// Representa el resultado del alineamiento
struct AlignmentResult {
    std::string aligned_seq1;
    std::string aligned_seq2;
    int score;
};

AlignmentResult needleman_wunsch(const std::string& seq1, const std::string& seq2, int match, int mismatch, int gap);

#endif

