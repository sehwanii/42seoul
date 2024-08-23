#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void replaceStringInFile(const std::string& filename, const std::string& s1, const std::string& s2) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open the input file." << std::endl;
        return;
    }

    std::ostringstream ss;
    ss << inputFile.rdbuf();
    std::string fileContents = ss.str();
    inputFile.close();

    std::string outputFilename = filename + ".replace";
    std::ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not open/create the output file." << std::endl;
        return;
    }
    size_t pos = 0;
    while ((pos = fileContents.find(s1, pos)) != std::string::npos) {
        fileContents.replace(pos, s1.length(), s2);
        pos += s2.length();
    }

    outputFile << fileContents;
    outputFile.close();
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <search_string> <replace_string>" << std::endl;
        return 1;
    }
    replaceStringInFile(argv[1], argv[2], argv[3]);
    return 0;
}