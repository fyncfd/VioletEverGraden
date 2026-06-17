#include <bits/stdc++.h>

long long x, y;

void solve() {
    std::cin >> x >> y;
    if (x == y) {
        std::cout << "1\n";
    } 
    else if ((x & y) == 0) {
        std::cout << "1\n";
    } 
    else {
        int num1 = x & y;
        int num2 = x | y;
        int num3 = x ^ y;
        int num4 = std::__gcd(x, y);
        bool ok = false;
        if (num1 == x || num1 == y || (num1 & x) == 0 || (num1 & y) == 0) {
            ok = true;
        }
        else if (num2 == x || num2 == y || (num2 & x) == 0 || (num2 & y) == 0) {
            ok = true;
        }
        else if (num3 == x || num3 == y || (num3 & x) == 0 || (num3 & y) == 0) {
            ok = true;
        }
        else if (num4 == x || num4 == y || (num4 & x) == 0 || (num4 & y) == 0) {
            ok = true;
        }
        std::cout << (ok ? "2\n" : "3\n");
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    
    int _ = 1;
    std::cin >> _;
    
    while (_ --) {
        solve();
    }
    
    return 0;
}