/*
* @Author: AlgoStruggler
* @Create Time: 2026-03-26 09:42:34
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
    int N, M, S;
    std::cin >> N >> M >> S;

    std::vector<std::vector<char>> g(N + 1);
    for (int i = 1; i <= N; i ++) {
    	for (int j = 1; j <= M; j ++) {
    		char c;
    		std::cin >> c;
    		g[i].push_back(c);
    	}
    	reverse(g[i].begin(), g[i].end());
    }

    std::vector<char> st;
    std::vector<char> q;
   	while (true) {
   		int x;
   		std::cin >> x;
   		if (x == -1) {
   			break;
   		}

   		if (x == 0) {
   			if (st.empty()) {
   				continue;
   			} else {
   				int f = st.back();
   				st.pop_back();
   				q.push_back(f);
   			}
   		} else {
   			if (g[x].empty()) {
   				continue;
   			} else {
   				if (st.size() < S) {
   					int f = g[x].back();
   					g[x].pop_back();
   					st.push_back(f);
   				} else {
   					int f = st.back();
   					st.pop_back();
   					q.push_back(f);
   					int d = g[x].back();
   					g[x].pop_back();
   					st.push_back(d);
   				}
   			}
   		}
   	}

   	for (int i = 0; i < q.size(); i ++) {
   		std::cout << q[i];
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