#include <iostream>
#include <fstream>
#include <string>
#include "stringdecoding.cpp"  // Including implementation directly (not ideal but works)

int main()
{
    std::ifstream inFile;
    std::ofstream outFile;
    std::string inputFileName, outputFileName;

    std::cout << "Enter input file name: ";
    std::cin >> inputFileName;
    inFile.open(inputFileName.c_str());

    if (!inFile)
    {
        std::cerr << "Error opening input file." << std::endl;
        return 1;
    }

    std::cout << "Enter output file name: ";
    std::cin >> outputFileName;
    outFile.open(outputFileName.c_str());

    if (!outFile)
    {
        std::cerr << "Error opening output file." << std::endl;
        return 1;
    }

    std::string exp, code;

    // Read the first two lines from the input file
    std::getline(inFile, exp);
    std::getline(inFile, code);

    std::string decoded = decode(exp, code);

    outFile << "Decoded string: " << decoded << std::endl;

    std::cout << "Decoding complete. Check output file." << std::endl;

    inFile.close();
    outFile.close();

    return 0;
}