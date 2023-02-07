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

/*Повільніший метод:шукаємо з першого символу повторення, якщо є — видаляємо їх, інакше — це і є перший унікальний символ*/
char getFirstUniqueSymbolSlow(std::string strOfUnique){

}

/*Швидший метод: відбувається всього 1 прохід по рядку унікальних символів слів початкового речення,
 * потім один прохід по масиву, що надає порядок додавання символів у мапу*/
char getFirstUniqueSymbolFast(std::string strOfUnique){
    std::unordered_map<char,int> symbolFreqMap;
    std::vector<char> symbolsPos;
    for(auto symbol:strOfUnique){
        symbolFreqMap[symbol]++;
        if(symbolFreqMap[symbol] == 1){
            symbolsPos.push_back(symbol);
        }
    }
    char result = *std::find_if(symbolsPos.begin(), symbolsPos.end(),[&symbolFreqMap](char symbol){
       if(symbolFreqMap[symbol] == 1)return true;
       else return false;
    });
    return result;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    std::string str = "Have a Hice ayy puppy uf course";
    std::string uniqueSymbols = findFirstUniqueStr(str);
    std::cout << getFirstUniqueSymbolFast(uniqueSymbols);
    return 0;
}
