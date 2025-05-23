#include <iostream>
#include "substring.h"
#include "needleman_wunsch.h"

int main() {
    std::string str1 = "AGCTTAGG";
    std::string str2 = "GAGTTGGG";

    std::cout << "str1: " << str1 << std::endl;
    std::cout << "str2: " << str2 << std::endl;
    std::cout << "Substring: " << smith_waterman(str1, str2) << std::endl;

    auto result = needleman_wunsch(str1, str2, 1, -1, -2);
    std::cout << "Aligned 1: " << result.aligned_seq1 << std::endl;
    std::cout << "Aligned 2: " << result.aligned_seq2 << std::endl;
    std::cout << "Score: " << result.score << std::endl;

    return 0;
}

