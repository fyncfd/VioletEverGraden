/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-14 19:34:20
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/#pragma GCC optimize("O3,unroll-loops,Ofast,inline")
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

    std::map<std::string, std::set<int>> mp;
    std::map<std::string, int> ct;
    for (int i = 1; i <= N; i ++) {
    	std::string id;
    	std::cin >> id;

    	int K;
    	std::cin >> K;

    	for (int i = 1; i <= K; i ++) {
    		int F;
    		std::cin >> F;
    		mp[id].insert(F);
    	}
    	ct[id] = K;
    }

    struct pii {
    	std::string name; int cnt;
    };
    std::vector<pii> ans;

    for (auto [x, y] : mp) {
    	ans.push_back({x, y.size()});
    }

    std::sort(ans.begin(), ans.end(), [&](pii a, pii b) -> bool {
    	if (a.cnt == b.cnt) {
    		return 1.0 * ct[a.name] / a.cnt < 1.0 * ct[b.name] / b.cnt;
    	}
    	return a.cnt > b.cnt;
    });

    if (ans.size() < 3) {
    	int t = 3 - ans.size();
    	for (int i = 0; i < ans.size(); i ++) {
    		std::cout << ans[i].name << ' ';
    	}
    	for (int i = 1; i <= t - 1; i ++) {
    		std::cout << "- ";
    	}
    	std::cout << "-\n";
    } else {
    	for (int i = 0; i < 3; i ++) {
    		std::cout << ans[i].name << " \n"[i == 2];
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