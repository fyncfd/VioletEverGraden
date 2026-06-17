/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-16 15:01:32
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
    int n, m;
    std::cin >> n >> m;

    std::string A;
    std::cin >> A;

    std::string B;
    std::cin >> B;

    i64 xorsumA = 0;
    for (auto c : A) {
    	int x = c - '0';
    	xorsumA ^= x;
    }

    i64 xorsumB = 0;
    for (auto c : B) {
    	int x = c - '0';
    	xorsumB ^= x;
    }

    if (xorsumA != xorsumB) {
    	std::cout << "NO\n";
    	return ;
    }

    int i = 0; int j = 0;
    while (i < A.size()) {
    	int cur = B[j] - '0';
    	int tmp = 0;
	    for (int k = i; k < n; k ++) {
	    	tmp ^= A[i] - '0';
	    	if (tmp == cur) {
	    		i = k;
	    		j ++;
	    		break;
	    	}
	    }
    }

    if (j == m) {
    	std::cout << "YES\n";
    } else {
    	std::cout << "NO\n";
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

    for (int _ = [&]() -> int { int T; std::cin >> T; return T; }(); _; _ --)
        VioletEverGraden();

    return 0;
}