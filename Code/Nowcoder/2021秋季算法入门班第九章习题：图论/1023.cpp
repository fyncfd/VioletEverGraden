/*
* @Author: AlgoStruggler
* @Create Time: 2026-05-08 15:20:11
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

constexpr int N = 2e5 + 10;

int fa[N];
int sz[N];

void init() {
	for (int i = 1; i <= N; i ++) {
		fa[i] = i;
		sz[i] = 0;
	}
}

int find(int x) {
	if (fa[x] != x) {
		int pre = fa[x];
		fa[x] = find(fa[x]);
		sz[x] += sz[pre];
	}
	return fa[x];
}

int min = INF;
bool merge(int u, int v) {
	int fu = find(u), fv = find(v);
	if (fu != fv) {
		fa[fu] = fv;
		sz[fu] = sz[u] + sz[v] + 1;
		return true;
	} else {
		min = std::min(min, sz[u] + sz[v] + 1);
		return false;
	}
}

static inline void VioletEverGraden() {
    int n;
    std::cin >> n;

    init();

    for (int u = 1; u <= n; u ++) {
    	int v;
    	std::cin >> v;
    	merge(u, v);
    }

    std::cout << min << '\n';
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