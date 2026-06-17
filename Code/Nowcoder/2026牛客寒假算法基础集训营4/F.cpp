/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-09 14:29:56
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#define  _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O2")
#include "bits/stdc++.h"
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using ldb = long double;
typedef __int128 i128;
typedef unsigned __int128 u128;

const double eps = 1e-9;
constexpr int INF = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr i64 mod = 998244353;
constexpr i64 MOD = 1e9 + 7;
constexpr int MAXN = 0;

static inline void VioletEverGraden() {
    int a, b;
    std::cin >> a >> b;

/*    bool ok = false;
    if (a < b) {
        std::swap(a, b);
        ok = true;
    }

    std::string ans = "";
    while (a > 0 or b > 0) {
        if (a > b) {
            ans.push_back('0');
            a --;
            if (b > 0) {
                ans.push_back('1');
                b --;
            }
        } else {
            if (b > 0) {
                ans.push_back('1');
                b --;
            } 
            if (a > 0) {
                ans.push_back('0');
                a --;
            }
        }
    }

    if (ok) {
        for (auto &c : ans) {
            if (c == '1') {
                c = '0';
            } else {
                c = '1';
            }
        }
    }*/

    if (a >= b) {
        int cnt = b + 1;
        int cur = a / cnt;
        int p = a % cnt;

        for (int i = 0; i < cnt; i ++) {
            int num = cur + (i < p ? 1 : 0);
            for (int j = 0; j < num; j ++) {
                std::cout << '0';
            }
            if (i < b) {
                std::cout << '1';
            }
        }
    } else {
        int cnt = a + 1;
        int cur = b / cnt;
        int p = b % cnt;

        for (int i = 0; i < cnt; i ++) {
            int num = cur + (i < p ? 1 : 0);
            for (int j = 0; j < num; j ++) {
                std::cout << '1';
            }
            if (i < a) {
                std::cout << '0';
            }
        }
    }
    std::cout << '\n';
    
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

2
1 1
2 1

01
010

2
5 6
4 5

10101010101
101010101


*/
}

signed main() {
#ifdef Algostruggler
    freopen("A.in", "r", stdin);
#endif // Algostruggler

    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    /*std::cout << std::fixed << std::setprecision(9);
    std::cerr << std::fixed << std::setprecision(9);*/

    int _ = 1;
    for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}