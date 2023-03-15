#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    std::ifstream infile("../../test/example.txt");
    std::string line;
    if (!infile){
        cout << "anjay" << endl;
    }

    while (std::getline(infile, line)) {
        // Process the line here
        // For example, you can split the line into words using stringstream
        istringstream iss(line);
        string word;
        while (iss >> word) {
            // Process the word here
            std::cout << word << std::endl;
        }
    }

    return 0;
}
