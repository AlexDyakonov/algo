#include <iostream>
#include <cmath>

bool checkOnNines(long long number) {
    while (number > 0) {
        if (number % 10 != 9) {
            return false;
        }
        number /= 10;
    }
    return true;
}

long long generateNines(long long nNines) {
    long long ans = 0;
    for (long long i = 0; i < nNines; i++) {
        ans += 9 * std::pow(10, i);
    }
    return ans;
}

long long factorial(long long n) {
    long long fact = 1;
    for (long long i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    long long nShovels;
    std::cin >> nShovels;

    long long sumLast = nShovels + (nShovels - 1);

    if (checkOnNines(sumLast)) {
        std::cout << 1 << std::endl;
    } else if (nShovels < 5) {
        std::cout << factorial(nShovels) / (2 * factorial(nShovels - 2)) << std::endl;
    } else {
        long long nNines = std::to_string(sumLast).length() - 1;
        long long answer = 0;
        long long p = generateNines(nNines);
        for (long long i = 0; i < 9; i++) {
            if (p <= (nShovels + 1)) answer += p / 2;
            else if (p > sumLast) {
 
             } else {
                answer += (nShovels - (p - nShovels) + 1) / 2;
            }
            p += std::pow(10, nNines);
        }
        std::cout << answer << std::endl;
    }

    return 0;
}
