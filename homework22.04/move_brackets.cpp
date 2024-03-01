#include <iostream>
#include <string>

int calculate(const std::string& line) {
    int count_open_brackets = 0;
    int count_closed_brackets = 0;
    int count_negative_balance = 0;

    for (char bracket : line) {
        switch (bracket) {
            case ')': count_closed_brackets++; break;
            case '(': count_open_brackets++; break;
        }
        int balance = count_open_brackets - count_closed_brackets;
        if (balance < 0) {
            count_negative_balance++;
            count_closed_brackets--;
        }
    }
    return count_negative_balance;
}

int main() {
    int countTests;
    std::cin >> countTests;
    std::cin.ignore();

    std::string line;
    for (int i = 0; i < countTests; ++i) {
        getline(std::cin, line); 
        getline(std::cin, line);
        std::cout << calculate(line) << std::endl;
    }

    return 0;
}