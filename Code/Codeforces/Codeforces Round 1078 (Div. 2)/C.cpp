/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-10 17:50:06
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#define  _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O2")
#include "bits/stdc++.h"
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using ldb = long double;
typedef __int128 i128;
typedef unsigned __int128 u128;

const double eps = 1e-9;
constexpr int INF = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr i64 mod = 998244353;
constexpr i64 MOD = 1e9 + 7;
constexpr int MAXN = 0;

static inline void VioletEverGraden() {
    int n, k;
    std::cin >> n >> k;

    std::vector<std::string> s(k);
    for (int i = 0; i < k; i ++) {
    	std::cin >> s[i];
    }

    std::vector<std::map<char, int>> mp(n);
    for (int i = 0; i < n; i ++) {
	    for (int j = 0; j < k; j ++) {
	    	mp[i][s[j][i]] ++;
	    }
	}

	std::string ans = "";
	for (int len = 1; len <= n; len ++) {
		// bool okk = false;
		if (n % len == 0) {
			// std::cerr << "len :" << len << '\n';
			std::string tmp;
			for (int i = 0; i < len; i ++) {
				// bool okk = false;
				for (auto [x, y] : mp[i]) {
					// std::cerr << x << "??\n";
					bool ok = true;
					for (int j = i + len; j < n; j += len) {
						for (int l = 0; l < k; l ++) {
							// std::cout << s[l][j] << "_____\n";
						}
						if (!mp[j].count(x)) {
							ok = false;
							break;
						}
					} 
					if (ok) {
						tmp.push_back(x);
						break;
						// okk = true;
					}
				}
			}
			// std::cerr << tmp << "10086\n";
			if (tmp.size() == len) {
				for (int i = 1; i <= n / len; i ++) {
					ans = ans + tmp;
				}
				break;
			}
		}
	}

	std::cout << ans << '\n';
    
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

3
3 2
abc
baa
9 2
iiinnnfff
nnfiffinn
4 2
acbd
bdac

aaa
infinfinf
acac

1
4 2
acbd
bdac

acac


*/
}

signed main() {
#ifdef Algostruggler
    freopen("A.in", "r", stdin);
#endif // Algostruggler

    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    /*std::cout << std::fixed << std::setprecision(9);
    std::cerr << std::fixed << std::setprecision(9);*/

    int _ = 1;
    for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}