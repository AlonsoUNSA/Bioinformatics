#include <iostream>
#include "smith_waterman.hpp"
#include <fstream>

int main() {
    std::string str1 = "AGCTTAGG";
    std::string str2 = "GAGTTGGG";

    // write into a file called "output.txt"
    std::ofstream outfile("output.txt");
    if (outfile.is_open()) {
        std::string local_align = smith_waterman(str1, str2);
        outfile.close();
    } else {
        std::cerr << "Unable to open file" << std::endl;
    }


    return 0;
}


