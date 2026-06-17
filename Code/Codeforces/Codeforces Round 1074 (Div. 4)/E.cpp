/*
* @Author: AlgoStruggler
* @Create Time: 2026-01-18 23:20:32
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#define  _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O2")
#include "bits/stdc++.h"
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;

using i64 = long long;
using ldb = long double;
typedef unsigned long long u64;
typedef __int128 i128;
struct pll { i64 fi; i64 se; };
#define debug(x) std::cerr << #x << " = " << x << '\n'
#define debug2(x, y) std::cerr << #x << " = " << x << ", " << #y << " = " << y << '\n'
/*------------------------------SORT_AND_UNIQUE-------------------------------*/
const double eps = 1e-9;
constexpr int INF = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr i64 mod = 998244353;
constexpr i64 MOD = 1e9 + 7;
constexpr int MAXN = 0;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<i64> a(n + 1);
    for (int i = 1; i <= n; i ++) {
    	std::cin >> a[i];
    }

    std::vector<i64> b(m + 1);
    for (int i = 1; i <= m; i ++) {
    	std::cin >> b[i];
    }

    std::string s;
    std::cin >> s;

    std::sort(b.begin() + 1, b.end(), [&](i64 x, i64 y) -> bool {
    	return x < y;
    });

    struct pii {
    	i64 dis; int id;
    };
    std::vector<pii> l; std::vector<pii> r;

    for (int i = 1; i <= n; i ++) {
    	auto it = std::lower_bound(b.begin() + 1, b.end(), a[i]);

    	if (it != b.end()) {
    		r.push_back({*it - a[i], i});
    	}

    	if (it != b.begin() + 1) {
    	}
    }

    std::sort(l.begin(), l.end(), [](pii x, pii y) -> bool {
        return x.dis > y.dis;
    });
    std::sort(r.begin(), r.end(), [](pii x, pii y) -> bool {
        return x.dis < y.dis;
    });
 
    i64 pos = 0;
    i64 min = 0; i64 max = 0;
    int pl = 0;int pr = 0;
    std::vector<bool> d(n + 1, false);
    int num = n;
    
    for (char c : s) {
        if (c == 'L') {
            pos --;
        } else {
            pos ++;
        }

        if (pos < min) {
            min = pos;
            while (pl < l.size() and l[pl].dis >= min) {
                int idx = l[pl].id;
                if (!d[idx]) {
                    d[idx] = true;
                    num --;
                }
                pl ++;
            }
        } else if (pos > max) {
            max = pos;
            while (pr < r.size() and r[pr].dis <= max) {
                int idx = r[pr].id;
                if (!d[idx]) {
                    d[idx] = true;
                    num --;
                }
                pr ++;
            }
        }

        std::cout << num << ' ';
    }
    std::cout << '\n';

    /*太好了，这回只花998244353min就打完了!
    真好。记得多手造几组。ACM拍什么拍。 */
/*
Test Sample

*/
}
/*-----------------------------Algostruggler----------------------------------*/
signed main() {
#ifdef LOCAL
    freopen("A.in", "r", stdin);
#endif // LOCAL

    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    /*std::cout << std::fixed << std::setprecision(9);
    std::cerr << std::fixed << std::setprecision(9);*/

    int _ = 1;
    for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}