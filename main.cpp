#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void compressRLE(const std::string &input, const std::string &output) {
    std::ifstream inFile(input);
    std::ofstream outFile(output);
    
    if (!inFile.is_open() || !outFile.is_open()) {
        std::cerr << "Error opening files!" << std::endl;
        return;
    }
    
    char prevChar;
    int count = 1;
    inFile.get(prevChar);

    char currentChar;
    while (inFile.get(currentChar)) {
        if (currentChar == prevChar) {
            count++;
        } else {
            outFile << prevChar << count;
            prevChar = currentChar;
            count = 1;
        }
    }

    outFile << prevChar << count;

    inFile.close();
    outFile.close();
}

void decompressRLE(const std::string &input, const std::string &output) {
    std::ifstream inFile(input);
    std::ofstream outFile(output);
    
    if (!inFile.is_open() || !outFile.is_open()) {
        std::cerr << "Error opening files!" << std::endl;
        return;
    }

    char currentChar;
    int count;

    while (inFile >> currentChar >> count) {
        for (int i = 0; i < count; ++i) {
            outFile << currentChar;
        }
    }

    inFile.close();
    outFile.close();
}

int main() {
    std::string inputFile = "input.txt";
    std::string outputFile = "compressed.txt";
    compressRLE(inputFile, outputFile);
    //decompressRLE(inputFile, outputFile); //Uncomment to decompress
    std::cout << "Compression complete!" << std::endl;
    return 0;
}