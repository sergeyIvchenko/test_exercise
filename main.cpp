#include <iostream>
#include <vector>
#include <windows.h>
#include <algorithm>
#include <sstream>

std::string findFirstUniqueStr(std::string& input) {
    std::istringstream sstream(input);
    std::string word;
    std::string result = "";
    while (sstream >> word) {
        for (auto symbol: word) {
            int symbolFrequency = std::count(word.begin(), word.end(), symbol);
            if (symbolFrequency == 1) {
                result += symbol;
                break;
            }
        }
    }
    return result;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    return 0;
}
