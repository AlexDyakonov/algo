#include <iostream>
#include <string>

int calculate(const std::string& line) {
    int count_open_brackets = 0, 
        count_closed_brackets = 0,
        count_negative_balance = 0;

    for (char bracket : line) {
        switch (bracket) {
            case ')': ++count_closed_brackets; break;
            case '(': ++count_open_brackets; break;
        }
        if ((count_open_brackets - count_closed_brackets) < 0) {
            ++count_negative_balance;
            --count_closed_brackets;
        }
    }
    return count_negative_balance;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

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