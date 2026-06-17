#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 N;
    std::cin >> N;

    int maxLen = 0, ST = 0;
    i64 temp;
    for (int i = 2; i <= sqrt(N); i ++) {
        temp = N;
        int j = i;
        while (temp % j == 0) {
            temp /= j;
            j ++;
        }
        if (j - i > maxLen) {
            maxLen = j - i;
            ST = i;
        }
    }

    if (maxLen == 0) {
        std::cout << 1 << "\n" << N << "\n";
    } else {
        std::cout << maxLen << "\n";
        for (int i = 0; i < maxLen; i ++) {
            if (i > 0) std::cout << "*";
            std::cout << ST + i;
        }
        std::cout << "\n";
    }

    return 0;
}