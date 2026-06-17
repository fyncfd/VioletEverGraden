/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-15 20:03:21
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
    int n;
    std::cin >> n;

    std::map<std::string, bool> vis;
    for (int i = 1; i <= n; i ++) {
    	std::string s;
    	std::cin >> s;
    	vis[s] = true;
    }

    int m;
    std::cin >> m;
    int sum = 0;
    std::map<std::string, int> mp;
    for (int i = 1; i <= m; i ++) {
    	std::string s; int n;
    	std::cin >> s >> n;
    	sum += n;
    	mp[s] = n;
    }

    double avg = 1.0 * sum / m;

    std::vector<std::string> ans;
    for (auto [x, y] : mp) {
    	if (!vis[x]) {
    		if (y > avg) {
    			ans.push_back(x);
    		}
    	}
    }

    if (ans.size() == 0) {
    	std::cout << "Bing Mei You\n";
    	return ;
    }

    std::sort(ans.begin(), ans.end(), [&](std::string a, std::string b) -> bool {
    	return a < b;
    });

    for (int i = 0; i < ans.size(); i ++) {
    	std::cout << ans[i] << '\n';
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