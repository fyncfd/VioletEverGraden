/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-13 18:29:14
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

    std::map<int, double> sum;
    std::map<int, int> cnt;

    for (int i = 1; i <= N; i ++) {
    	int K;
    	std::cin >> K;

    	double Sum = 0;
    	for (int j = 1; j <= K; j ++) {
    		int n, p;
    		std::cin >> n >> p;

    		Sum += p;
    		sum[n] += p;
    		cnt[p] ++;
    	}
    	sum[i] -= Sum;
    }

    struct pii {
    	int id; double w; int num;
    };
    std::vector<pii> ans;
    for (auto [x, y] : sum) {
    	ans.push_back({x, y, cnt[x]});
    }

    std::sort(ans.begin(), ans.end(), [&](pii a, pii b) -> bool {
    	if (a.w == b.w) {
    		return a.num > b.num;
    	}
    	return a.w > b.w;
    });

    for (int i = 0; i < ans.size(); i ++) {
    	std::cout << ans[i].id << ' ';
    	std::cout << std::fixed << std::setprecision(2) << ans[i].w * 0.01 << '\n';
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