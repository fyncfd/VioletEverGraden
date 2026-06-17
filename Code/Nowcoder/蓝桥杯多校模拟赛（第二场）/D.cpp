/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-06 14:27:53
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
    std::string s;
    std::cin >> s;

    int n = s.length();
    int ans = 0;
    
    for (int i = 0; i < n; i ++) {
        if (s[i] == '(') {
            int j = i + 1;
            while (j < n && s[j] != ')') {
                j ++;
            }
            if (j >= n) {
            	break;
            }

            bool ok1 = true;
            bool ok2 = false;
            int sum = 0;
            int num = 0;
            
            for (int k = i + 1; k < j; k ++) {
                char c = s[k];
                if (c == '(' || c == ')') {
                    ok1 = false;
                    break;
                }
                
                if (isdigit(c)) {
                    ok2 = true;
                    num = num * 10 + (c - '0');
                } else if (c == '.') {
                    if (num > 0) {
                        sum += num;
                        num = 0;
                    }
                } else {
                    ok1 = false;
                    break;
                }
            }

            if (num > 0) {
                sum += num;
            }

            if (ok1 && ok2) {
                ans = std::max(ans, sum);
            }

            i = j;
        }
    }
    
    std::cout << ans << '\n';
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

(21.4(1()2)

0

(3.32.1)1(3.46.)2)

49


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