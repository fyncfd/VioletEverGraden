/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-15 12:38:14
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

    std::vector<int> a(N + 1);
    for (int i = 1; i <= N; i ++) {
    	std::cin >> a[i];
    }

    std::sort(a.begin() + 1, a.end(), [&](int a, int b) -> bool {
    	return a < b;
    });

    if (N % 2 == 0) {
    	int sum1 = std::accumulate(a.begin() + 1, a.begin() + 1 + N / 2, 0LL);
    	int sum2 = std::accumulate(a.begin() + 1 + N / 2, a.end(), 0LL);
    	std::cout << "Outgoing #: " << N / 2 << '\n';
    	std::cout << "Introverted #: " << N / 2 << '\n';
    	std::cout << "Diff = " << sum2 - sum1 << '\n';
    } else {
    	int sum10 = 0, sum20 = 0;
    	for (int i = 1; i <= N / 2; i ++) {
    		sum10 += a[i];
    	}
    	for (int i = N / 2 + 1; i <= N; i ++) {
    		sum20 += a[i];
    	}

    	int sum11 = 0, sum21 = 0;
    	for (int i = 1; i <= N / 2 + 1; i ++) {
    		sum11 += a[i];
    	}
    	for (int i = N / 2 + 2; i <= N; i ++) {
    		sum21 += a[i];
    	}

    	int dif1 = sum20 - sum10;
    	int dif2 = sum21 - sum11;
    	if (dif1 > dif2) {
	    	std::cout << "Outgoing #: " << N / 2 + 1 << '\n';
	    	std::cout << "Introverted #: " << N / 2 << '\n';
	    	std::cout << "Diff = " << dif1 << '\n';
    	} else {
	    	std::cout << "Outgoing #: " << N / 2 << '\n';
	    	std::cout << "Introverted #: " << N / 2 + 1 << '\n';
	    	std::cout << "Diff = " << dif2 << '\n';
    	}
    }
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

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