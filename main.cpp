#include <iostream>
#include <vector>
#include <windows.h>
#include <algorithm>
#include <sstream>


char getFirstUniqueSymbol(std::string word){
    for (auto symbol: word) {
        int symbolFrequency = std::count(word.begin(), word.end(), symbol);
        if (symbolFrequency == 1) {
            return symbol;
        }
    }
    return ' ';
}
std::string findFirstUniqueStr(std::string& input) {
    std::istringstream sstream(input);
    std::string word;
    std::string result = "";
    while (sstream >> word) {
        result += getFirstUniqueSymbol(word);
    }
    return result;
}

///Повільніший метод:шукаємо з першого символу повторення, якщо є — видаляємо їх, інакше — це і є перший унікальний символ
char getFirstUniqueSymbolSlow(std::string strOfUnique){
    return getFirstUniqueSymbol(strOfUnique);
}

///Швидший метод: відбувається всього 1 прохід по рядку унікальних символів слів початкового речення,
///потім один прохід по масиву, що надає порядок додавання символів у мапу
char getFirstUniqueSymbolFast(std::string strOfUnique){
    std::unordered_map<char,int> symbolFreqMap;
    std::vector<char> symbolsPos;
    for(auto symbol:strOfUnique){
        symbolFreqMap[symbol]++;
        if(symbolFreqMap[symbol] == 1){
            symbolsPos.push_back(symbol);
        }
    }
    char result = ' ';
    std::find_if(symbolsPos.begin(), symbolsPos.end(),[&symbolFreqMap,&result](char symbol){
       if(symbolFreqMap[symbol] == 1){
           result = symbol;
           return true;
       }
       else return false;
    });
    if(result == ' ')std::cout << "Унікального першого символу слів речення не знайдено";
    return result;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    std::string str = "C makes it easy for you to shoot yourself in the foot. C++ makes that harder, but when you do, it blows away your whole leg. (с) Bjarne Stroustrup";
    std::string uniqueSymbols = findFirstUniqueStr(str);
    std::cout << "Результат знаходження першого унікального символу для двох алгоритмів:" << std::endl;
    std::cout << "1 - алгоритм: " << getFirstUniqueSymbolSlow(uniqueSymbols) << std::endl;
    std::cout << "2 - алгоритм: " << getFirstUniqueSymbolFast(uniqueSymbols) << std::endl;
    return 0;
}
