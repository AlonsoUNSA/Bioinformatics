#include "substring.h"
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>


std::string smith_waterman(const std::string& str1 , const std::string& str2) {
    // smith-waterman algorithm
    // Initialize the scoring matrix
    int m = str1.size();
    int n = str2.size();
    std::vector<std::vector<int>> score(m + 1, std::vector<int>(n + 1, 0));

    // Fill the scoring matrix
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            int match = (str1[i - 1] == str2[j - 1]) ? 1 : -1;
            int score_diag = score[i - 1][j - 1] + match;
            int score_up = score[i - 1][j] - 2;
            int score_left = score[i][j - 1] - 2;
            score[i][j] = std::max({0, score_diag, score_up, score_left});
        }
    }
    // Find the maximum score
    int max_score = 0;
    int max_i = 0, max_j = 0;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (score[i][j] > max_score) {
                max_score = score[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }
    // Traceback to find the local alignment
    std::string local_alignment;
    while(max_i > 0 && max_j > 0 && score[max_i-1][max_j-1]+1 == score[max_i][max_j] && score[max_i][max_j] > 0) {
        local_alignment = str1[max_i - 1]+local_alignment;
        max_i--;
        max_j--;
    }
    return local_alignment;
}

