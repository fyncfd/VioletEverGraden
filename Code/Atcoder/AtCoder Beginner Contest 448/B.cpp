/*
* @Author: AlgoStruggler
* @Create Time: 2026-03-07 20:03:46
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
    int N, M;
    std::cin >> N >> M;

    std::vector<int> C(M + 1);
    for (int i = 1; i <= M; i ++) {
    	std::cin >> C[i];
    }

    std::vector<int> A(N + 1), B(N + 1);
    for (int i = 1; i <= N; i ++) {
    	std::cin >> A[i] >> B[i];
    }

    std::vector<int> x(M + 1, 0);
    for (int i = 1; i <= N; i ++) {
    	x[A[i]] += B[i];
    }

    for (int i = 1; i <= M; i ++) {
    	x[i] = std::min(x[i], C[i]);
    }

    i64 sum = std::accumulate(x.begin() + 1, x.end(), 0LL);

    std::cout << sum << '\n';
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

7 5
4 4 8 3 7
1 2
2 3
5 2
4 10
2 3
5 4
2 3

15

1 1
1
1 1

1

15 10
7 94 100 82 63 81 75 2 76 73
10 44
5 77
10 47
7 32
2 82
5 90
3 37
6 70
6 28
3 25
2 26
10 56
1 69
5 46
7 26

438


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