/*
* @Author: AlgoStruggler
* @Create Time: 2026-03-17 11:48:21
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/

#pragma GCC optimize("O3,unroll-loops,Ofast,inline")
#include "bits/stdc++.h"

using i64 = int64_t;
using i128 =  __int128_t;

using u32 = uint32_t;
using u64 = uint64_t;
using u128 = __uint128_t;

using f32 = float;
using f64 = double;
using f80 = long double;

constexpr int INF = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr i64 mod = 998'244'353LL;
constexpr i64 MOD = 1e9 + 7;

static inline void VioletEverGraden() {
    int N;
    std::cin >> N;

    std::vector<int> S1;
    for (int i = 1; i <= N; i++) {
        int x;
        std::cin >> x;
        S1.push_back(x);
    }

    std::vector<char> S2;
    for (int i = 1; i < N; i++) {
        char c;
        std::cin >> c;
        S2.push_back(c);
    }

    while (!S1.empty() && !S2.empty()) {
        int n1 = S1.back(); S1.pop_back();
        int n2 = S1.back(); S1.pop_back();
        char op = S2.back(); S2.pop_back();

        if (op == '+') {
            int n = n2 + n1;
            S1.push_back(n);
        } else if (op == '-') {
            int n = n2 - n1;
            S1.push_back(n);
        } else if (op == '*') {
            int n = n2 * n1;
            S1.push_back(n);
        } else if (op == '/') {
            if (n1 == 0) {
                std::cout << "ERROR: " << n2 << "/0" << std::endl;
                return;
            }
            int n = n2 / n1;
            S1.push_back(n);
        }
    }

    if (!S1.empty()) {
        std::cout << S1.back() << std::endl;
    }
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

5
40 5 8 3 2
/ * - +
输出：2

5
2 5 8 4 4
* / - +
输出：ERROR: 5/0

*/
}

signed main() {
#ifdef Algostruggler
    freopen("A.in", "r", stdin);
#endif // Algostruggler

    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    // std::cout << std::fixed << std::setprecision(12), std::cerr << std::fixed << std::setprecision(12);

    // for (int _ = [&]() -> int { int T; std::cin >> T; return T; }(); _; _ --)
        VioletEverGraden();

    return 0;
}