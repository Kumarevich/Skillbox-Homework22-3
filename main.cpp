#include <iostream>
#include <map>
#include <string>

int main() {
    std::string first;
    std::string second;
    std::map<char, int> word;
    std::cout << "Input first word: ";
    std::cin >> first;
    std::cout << "Input second word: ";
    std::cin >> second;
    std::map<char, int>::iterator it;

    if (first.length() != second.length()) {
        std::cout << "false";
        return 1;
    }

    for (int i = 0; i < first.length(); ++i) {
        it = word.find(first[i]);
        if (it == word.end()) word.insert(std::pair<char, int>(first[i],1));
        else ++it->second;
    }

    for (int i = 0; i < second.length(); ++i) {
        it = word.find(second[i]);
        if (it == word.end()) {
            std::cout << "false";
            return 2;
        } else {
            --it->second;
            if (it->second == 0) word.erase(second[i]);
        }
    }

    std::cout << "true";
    return 0;
}
