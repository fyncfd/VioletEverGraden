/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-05 12:13:52
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
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for (int i = 0; i < n; i ++) {
    	std::cin >> a[i];
    }

    std::vector<int> st; std::queue<int> qu;
    std::vector<int> ans1, ans2;
    int __ = q;
    while (__ --) {
    	int op;
    	std::cin >> op;
    	if (op == 1) {
    		int x;
    		std::cin >> x;
    		st.push_back(x);
    		qu.push(x);
    	} else {
    		int x = st.back(); st.pop_back();
    		int y = qu.front(); qu.pop();
    		ans1.push_back(x); ans2.push_back(y);
    	}
    }

    bool ok1 = false;
    if (ans1 == a) {
    	ok1 = true;
    }

    bool ok2 = false;
    if (ans2 == a) {
    	ok2 = true;
    }

    if (ok1 && !ok2) {
    	std::cout << "stack\n";
    } else if (!ok1 && ok2) {
    	std::cout << "queue\n";
    } else if (!ok1 && !ok2) {
    	std::cout << -1 << '\n';
    } else {
    	std::cout << "both\n";
    }
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

1 2
1
1 1
2

both

1 3
1
1 1
1 2
2

queue

1 3
2
1 1
1 2
2

stack

1 3
2
1 1
1 1
2

-1


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