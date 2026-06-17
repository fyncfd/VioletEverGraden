/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-13 15:05:45
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
    int n, w;
    std::cin >> n >> w;

	struct Node {
	    f64 w;
	    i64 x;
	    i64 r;

	    bool operator < (const Node& a) const {
	        return w < a.w;
	    }
	};

    std::priority_queue<Node> heap;
    f64 sum = 0.0;
    for (int i = 1; i <= n; i ++) {
        i64 x, y;
        std::cin >> x >> y;
        sum += sqrt((f64)x * x + (f64)y * y);
        
        if (y > 0) {
            f64 w = sqrt((f64)x * x + (f64)y * y) - sqrt((f64)x * x + (f64)(y - 1) * (y - 1));
            heap.push({w, x, y});
        }
    }

    while (w -- > 0 && !heap.empty()) {
        Node cur = heap.top();
        heap.pop();
        if (cur.w <= 1e-12 || cur.r == 0) {
            break;
        }

        sum -= cur.w;
        i64 nr = cur.r - 1;
        if (nr > 0) {
            f64 nw = sqrt((f64)cur.x * cur.x + (f64)nr * nr) - sqrt((f64)cur.x * cur.x + (f64)(nr - 1) * (nr - 1));
            heap.push({nw, cur.x, nr});
        }
    }

    std::cout << sum << '\n';
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

2 1
3 4
5 12

17.083045973595

1 10
3 4

3.000000000000


*/
}

signed main() {
#ifdef Algostruggler
    freopen("A.in", "r", stdin);
#endif // Algostruggler

    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    std::cout << std::fixed << std::setprecision(12), std::cerr << std::fixed << std::setprecision(12);

    // for (int _ = [&]() -> int { int T; std::cin >> T; return T; }(); _; _ --)
        VioletEverGraden();

    return 0;
}