#include<iostream>
#include<string>
#include<algorithm>
std::string identifyString(const std::string& original_str){
    std::string str = original_str;
    //convert to uppercase
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    auto is_dna = [](const std::string& s){
        const std::string dna_bases = "ACGT";
        return std::all_of(s.begin(),s.end(),[&dna_bases](char c){
            return dna_bases.find(c)!= std::string::npos;
        });
    };

    auto is_rna = [](const std::string& s){
        const std::string rna_bases = "ACGU";
        return std::all_of(s.begin(),s.end(),[&rna_bases](char c){
            return rna_bases.find(c)!= std::string::npos;
        });
    };

    auto is_protein = [](const std::string& s){
        const std::string protein_bases = "ACDEFGHIKLMNPQRSTVWY";
        return std::all_of(s.begin(),s.end(),[&protein_bases](char c){
            return protein_bases.find(c)!= std::string::npos;
        });
    };
    if(is_rna(str))
        return "ARN";
    if(is_dna(str))
        return "DNA";
    if(is_protein(str))
        return "Protein"; 
    else
        return "Unknown";
}
// from DNA to RNA
std::string dnaToRna(const std::string& dna){
    std::string rna = dna;
    std::replace(rna.begin(), rna.end(), 'T', 'U');
    return rna;
}

// identify protein from DNA
std::string dnaToProtein(const std::string& dna){
    std::string protein;
    for (size_t i = 0; i < dna.length(); i += 3) {
        std::string codon = dna.substr(i, 3);
        if (codon == "GCU" || codon == "GCC" || codon == "GCA" || codon == "GCG") {
            protein += 'A'; // Alanine
        } else if (codon == "UGU" || codon == "UGC") {
            protein += 'C'; // Cysteine
        } else if (codon == "GAU" || codon == "GAC") {
            protein += 'D'; // Aspartic acid
        } else if (codon == "GAA" || codon == "GAG") {
            protein += 'E'; // Glutamic acid
        } else if (codon == "UUU" || codon == "UUC") {
            protein += 'F'; // Phenylalanine
        } else if (codon == "GGU" || codon == "GGC" || codon == "GGA" || codon == "GGG") {
            protein += 'G'; // Glycine
        } else if (codon == "CAU" || codon == "CAC") {
            protein += 'H'; // Histidine
        } else if (codon == "AUU" || codon == "AUC" || codon == "AUA") {
            protein += 'I'; // Isoleucine
        } else if (codon == "AAA" || codon == "AAG") {
            protein += 'K'; // Lysine
        } else if (codon == "AUG") {
            protein += 'M'; // Methionine
        } else if (codon == "AAU" || codon == "AAC") {
            protein += 'N'; // Asparagine
        } else if (codon == "CCU" || codon == "CCC" || codon == "CCA" || codon == "CCG") {
            protein += 'P'; // Proline
        } else if (codon == "CAA" || codon == "CAG") {
            protein += 'Q'; // Glutamine
        } else if (codon == "CGU" || codon == "CGC" || codon == "CGA" || codon == "CGG") {
            protein += 'R'; // Arginine
        } else if (codon == "UCU" || codon == "UCC" || codon == "UCA" || codon == "UCG") {
            protein += 'S'; // Serine
        } else if (codon == "ACU" || codon == "ACC" || codon == "ACA" || codon == "ACG") {
            protein += 'T'; // Threonine
        } else if (codon == "UGG") {
            protein += 'W'; // Tryptophan
        } else if (codon == "UAU" || codon == "UAC") {
            protein += 'Y'; // Tyrosine
        } else if (codon == "GUA" || codon == "GUC" || codon == "GUA" || codon == "GUG") {
            protein += 'V'; // Valine
        } else if (codon == "UAA" || codon == "UAG" || codon == "UGA") {
            break; // Stop codons
        }
        else {
            protein += '?'; // Unknown amino acid
        }
    }
    return protein;
}

// 
int main() {

    std::string sequence;
    std::cin >> sequence;
    std::cout << "The given sequence is: " << identifyString(sequence) << std::endl;
    if (identifyString(sequence) == "DNA") {
        std::cout << "its RNAm is: " << dnaToRna(sequence) << std::endl;
        std::cout << "the proteins are: " << dnaToProtein(dnaToRna(sequence)) << std::endl;
    }
    // TEST: 
    // g++ DNA_RNA_Protein_Identifier.cc -o indentifier.out
    // echo "ATGGAAGTATTTAAAGCGCCACCTATTGGGATATAAG" | ./identifier.out
    return 0;
}