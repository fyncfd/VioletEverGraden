/*
* @Author: AlgoStruggler
* @Create Time: 2026-03-07 20:09:10
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
	int N, Q;
    std::cin >> N >> Q;

    std::vector<i64> A(N + 1);
    std::vector<std::pair<i64, int>> v;
    for (int i = 1; i <= N; i ++) {
        std::cin >> A[i];
        v.emplace_back(A[i], i);
    }

    std::sort(v.begin(), v.end());
    
    while (Q--) {
        int K;
        std::cin >> K;
        
        std::vector<int> B(K);
        for (int i = 0; i < K; i ++) {
            std::cin >> B[i];
        }

        for (int i = 0; i <= K && i < N; i ++) {
            bool ok = false;
            for (int j = 0; j < K; j++) {
                if (v[i].second == B[j]) {
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                std::cout << v[i].first << '\n';
                break;
            }
        }
    }
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

6 6
3 2 5 9 1 2
2
4 5
5
1 2 3 4 6
3
2 5 6
4
1 2 5 6
1
5
3
1 2 3

2
1
3
5
2
1


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