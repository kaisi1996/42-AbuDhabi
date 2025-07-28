#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

void replaceOccurrences(std::string& content, const std::string& s1, const std::string& s2) 
{
    size_t position = content.find(s1);

    while (position != std::string::npos)
    {
        content.erase(position, s1.length());
        content.insert(position,s2);
        position = content.find(s1, position + s2.length());
    }
}

std::string readFromFile(const std::string& filename) 
{
    std::ifstream inFile;
    inFile.open(filename.c_str());

    if (!inFile.is_open())
    {
        std::cerr << "Error: Unable to open the input file\n";
        exit(1);
    }

    std::string line;
    std::getline(inFile, line, '\0');
    inFile.close();

    return line;
}

void writeToFile(const std::string& filename, const std::string& content) {
    
    std::ofstream outFile;
    outFile.open(filename.c_str());
    if (!outFile.is_open()) {
        std::cerr << "Error: Unable to create the output file\n";
        exit(1);
    }

    outFile << content;
    outFile.close();
}

int main(int argc, char** argv) 
{
    if (argc != 4) 
    {
        std::cout << "Usage: " << argv[0] << " <filename> <s1> <s2>\n";
        return 1; 
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    if (s1.empty()  || s2.empty())
	{
		std::cout << "Error: Empty string" << std::endl;
		return (1);
	}

    std::string content = readFromFile(filename);

    replaceOccurrences(content, s1, s2);


    std::string outFile = filename + ".replace";
    writeToFile(outFile, content);

    std::cout << "Replacement completed. Output written to: " << outFile << std::endl;

    return 0; 
}