#include "needleman_wunsch.h"
#include <iostream>
#include <algorithm>

AlignmentResult needleman_wunsch(const std::string& seq1, const std::string& seq2, int match, int mismatch, int gap) {
    int m = seq1.size(), n = seq2.size();
    std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1));

    // Rellenar la tabla

    for (int i = 0; i <= m; ++i) dp[i][0] = i * gap;
    for (int j = 0; j <= n; ++j) dp[0][j] = j * gap;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            int score_diag = dp[i-1][j-1] + (seq1[i-1] == seq2[j-1] ? match : mismatch);
            int score_up = dp[i-1][j] + gap;
            int score_left = dp[i][j-1] + gap;
            dp[i][j] = std::max({score_diag, score_up, score_left});
            std::cout << dp[i][j] << "\t ";
        }
        std::cout << std::endl;
    }


    // Backtracking y desarrollar la alineación

    std::string aligned1, aligned2;
    int i = m, j = n;
    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 &&
            dp[i][j] == dp[i-1][j-1] + (seq1[i-1] == seq2[j-1] ? match : mismatch)) {
            aligned1 = seq1[i-1] + aligned1;
            aligned2 = seq2[j-1] + aligned2;
            --i; --j;
        } else if (i > 0 && dp[i][j] == dp[i-1][j] + gap) {
            aligned1 = seq1[i-1] + aligned1;
            aligned2 = '-' + aligned2;
            --i;
        } else {
            aligned1 = '-' + aligned1;
            aligned2 = seq2[j-1] + aligned2;
            --j;
        }
    }

    return {aligned1, aligned2, dp[m][n]};
}

