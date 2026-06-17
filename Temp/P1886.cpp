/*单调队列
* @Author: AlgoStruggler
* @Create Time: 2026-02-25 12:17:12
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
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
    	std::cin >> a[i];
    }

    std::vector<int> min, max;
    std::deque<int> minq, maxq;
    for (int i = 1; i <= n; i ++) {
    	if (!minq.empty() && minq.front() <= i - k) {
    		minq.pop_front();
    	}
    	if (!maxq.empty() && maxq.front() <= i - k) {
    		maxq.pop_front();
    	}

    	while (!minq.empty() && a[minq.back()] > a[i]) {
    		minq.pop_back();
    	}
    	minq.push_back(i);
    	while (!maxq.empty() && a[maxq.back()] < a[i]) {
    		maxq.pop_back();
    	}
    	maxq.push_back(i);

    	if (i >= k) {
    		min.push_back(a[minq.front()]);
    		max.push_back(a[maxq.front()]);
    	}
    }

    for (int i = 0; i < min.size(); i ++) {
    	std::cout << min[i] << " \n"[i + 1 == min.size()];
    }

    for (int i = 0; i < max.size(); i ++) {
    	std::cout << max[i] << " \n"[i + 1 == max.size()];
    }
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

8 3
1 3 -1 -3 5 3 6 7

-1 -3 -3 -3 3 3
3 3 5 5 6 7


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