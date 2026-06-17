/*
* @Author: AlgoStruggler
* @Create Time: 2026-01-17 23:17:51
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#define  _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O2")
#include "bits/stdc++.h"
//#include <ext/pb_ds/assoc_container.hpp>

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef __int128 i128;
struct pii { int fi; int se; };
struct pll { ll fi; ll se; };

#define all(x) x.begin() + 1, x.end()
#define rep(i, l, r, x) for (decltype(l) i = (l); i <= (r); i += (x))
#define dep(i, l, r, x) for (decltype(l) i = (l); i >= (r); i -= (x))
#define lop(i, x) for (auto &i : x)
#define debug(x) std::cerr << #x << " = " << x << '\n'
#define debug2(x, y) std::cerr << #x << " = " << x << ", " << #y << " = " << y << '\n'
/*------------------------------SORT_AND_UNIQUE-------------------------------*/
//#define int long long
const double eps = 1e-9;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3f;
constexpr ll mod = 998244353;
constexpr ll MOD = 1e9 + 7;
int dx[] = {0, 0, 1, 0, -1 };
int dy[] = {0, -1, 0, 1, 0 };
constexpr int MAXN = 0;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int cnt0 = std::count(s.begin(), s.end(), '0');
    bool ok = true;
    for (int i = 0; i < cnt0; i ++) {
        if (s[i] != '0') {
            ok = false;
            break;
        }
    }
    if (ok) {
        for (int i = cnt0; i < n; i ++) {
            if (s[i] != '1') {
                ok = false;
                break;
            }
        }
    }

    if (ok) {
        std::cout << "Bob\n";
    } else {
        std::vector<int> ans;
        for (int i = 0; i < cnt0; i ++) {
            if (s[i] == '1') {
                ans.push_back(i + 1);
            }
        }
        for (int i = cnt0; i < n; i ++) {
            if (s[i] == '0') {
                ans.push_back(i + 1);
            }
        }

        std::cout << "Alice\n";
        std::cout << ans.size() << '\n';
        for (int idx : ans) {
            std::cout << idx << ' ';
        }
        std::cout << '\n';
   	}
    /*太好了，这回只花998244353min就打完了！*/
/*
Test Sample

3
3
000
2
10
3
101

Bob
Alice
2
1 2 
Alice
2
1 2


*/
}
/*-------------------------------Author_Fd------------------------------------*/
static inline void VioletEverGraden();

auto __FAST_IO__ = []() -> int {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    return 0;
}();

signed main() {
#ifdef LOCAL
    freopen("A.in", "r", stdin);
#endif // LOCAL

    /*std::cout << std::fixed << std::setprecision(9);
    std::cerr << std::fixed << std::setprecision(9);*/

    int _ = 1;
    for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}