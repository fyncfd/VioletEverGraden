/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-17 11:26:46
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

    std::cin.ignore();

    std::map<std::string, std::vector<std::string>> mp;
    for (int i = 1; i <= n; i ++) {
	    std::string s;
	    getline(std::cin, s);
	    std::stringstream ss(s);
	    std::string word;
	    std::string BG;
	    while (ss >> word) {
	    	char c = 'A' + word[0] - 'a';
	    	BG.push_back(c);
	    }
	    mp[BG].push_back(s);
    }

/*    for (auto [x, y] : mp) {
    	std::cout << x << '\n';
    	for (auto s : y) {
    		std::cout << s << "|";
    	}
    	std::cout << '\n';
    }*/

    int m;
    std::cin >> m;

    std::cin.ignore();

    for (int i = 1; i <= m; i ++) {
	    std::string s;
	    getline(std::cin, s);
	    std::stringstream ss(s);
	    std::string word;
	    std::string BG;
	    while (ss >> word) {
	    	char c = 'A' + word[0] - 'a';
	    	BG.push_back(c);
	    }
	    if (!mp.count(BG)) {
	    	std::cout << s << '\n';
	    } else {
	    	std::sort(mp[BG].begin(), mp[BG].end(), [&](std::string a, std::string b) -> bool {
	    		return a < b;
	    	});
	    	for (int i = 0; i < mp[BG].size(); i ++) {
	    		std::cout << mp[BG][i] << "|\n"[i + 1 == mp[BG].size()];
	    	}
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