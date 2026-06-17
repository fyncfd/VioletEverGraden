/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-14 19:03:01
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
    int N, k, M;
    std::cin >> N >> k >> M;

    std::vector<double> ans;
    for (int i = 1; i <= N; i ++) {
    	std::vector<int> a;
  		for (int j = 1; j <= k; j ++) {
  			int x;
  			std::cin >> x;
  			a.push_back(x);
  		}

  		std::sort(a.begin(), a.end(), [&](int a, int b) -> bool {
  			return a < b;
  		});

  		int sum = 0;
  		for (int i = 1; i + 1 < k; i ++) {
  			sum += a[i];
  		}

  		ans.push_back(1.0 * sum / (k - 2));
    }

    std::sort(ans.begin(), ans.end(), [&](double a, double b)-> bool {
    	return a < b;
    });

    for (int i = N - M; i <= N - 1; i ++) {
    	std::cout << std::fixed << std::setprecision(3) << ans[i] << " \n"[i + 1 == N];
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