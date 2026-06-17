/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-19 19:28:28
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
    // i64 a, b, c, l, r;
    // std::cin >> a >> b >> c >> l >> r;

	// i64 ans = r - l + 1;
	// // std::set<i64> s = {a, b, c};
	// for (i64 v : s) {
	//     ans -= (v >= l && v <= r);
	// }

	// std::cout << ans << '\n';





	std::string s;
	std::string s1;


	int pos = 0;
	std::vector<int> ans;
	int cnt = 0;
	while (s.find(s1, pos) != std::string::npos) {
		pos = s.find(s1, pos);
		ans.push_back(pos);
		cnt ++;
		if (cnt == 3) {
			break;
		}
	}

	int l, r;

	int len = r - l + 1;
	reverse(s.begin() + l, s.begin() + l + len)
std::string s3;

	s.insert(pos, s3);
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

1 2 3 1 4

1


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