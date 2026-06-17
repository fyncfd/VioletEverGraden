/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-16 09:40:41
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
    int N, M, K;
    std::cin >> N >> M >> K;

    std::vector<int> a;
    for (int i = 0; i < N; i ++) {
    	int x;
    	std::cin >> x;
    	a.push_back(x);
    }

    reverse(a.begin(), a.end());

    std::vector<std::vector<int>> ans;
    std::vector<int> z, h;
    while (a.size() || h.size()) {
    	z.clear();
    	
    	if (!h.empty()) {
    		int x = h.back();
    		h.pop_back();
    		z.push_back(x);
    	} else if (!a.empty()) {
    		int x = a.back();
    		a.pop_back();
    		z.push_back(x);
    	} else {
    		break;
    	}

    	while (z.size() < K) {
    		if (!h.empty() && h.back() <= z.back()) {
    			z.push_back(h.back());
    			h.pop_back();
    			continue;
    		}

            if (!a.empty()) {
                int next = a.back();
                if (next <= z.back()) {
                    z.push_back(next);
                    a.pop_back();
                    continue;
                } else {
                    if (h.size() < M) {
                        h.push_back(next);
                        a.pop_back();
                        continue;
                    } else {
                        break;
                    }
                }
            }

            if (a.empty()) {
                if (!h.empty() && h.back() <= z.back()) {
                    continue;
                } else {
                    break;
                }
            }
    	}

    	ans.push_back(z);
    }

    for (auto x : ans) {
    	for (int i = 0; i < x.size(); i ++) {
    		std::cout << x[i] << " \n"[i + 1 == x.size()];
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