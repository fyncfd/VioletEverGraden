/*
* @Author: AlgoStruggler
* @Create Time: 2026-01-13 18:43:37
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


//using namespace std;
//using namespace __gnu_pbds;
template<class T> using matrix = std::vector<std::vector<T>>;
template <typename T> using pq = std::priority_queue<T>;
template<class T> using matrix = std::vector<std::vector<T>>;
template <class Key, class Value> using ump = std::unordered_map<Key, Value>;
template <typename T> using ust = std::unordered_set<T>;
//template <typename Key, typename Value> using hash = __gnu_pbds::gp_hash_table<Key, Value>;
template<class T> concept Signed = std::is_signed_v<T>;
template<class T> concept Unsigned = std::is_unsigned_v<T>;
template<class T> concept Arithmetic = std::is_arithmetic_v<T>;
template<class T> std::istream &operator >> (std::istream &cin, std::vector<T> &a) {
    rep(i, 1, a.size() - 1, 1) {
        std::cin >> a[i];
    }
    return cin;
}
template<class T> std::ostream &operator << (std::ostream &cout, std::vector<T> &a) {
    int n = a.size() - 1;
    if (!n) {
        return cout;
    }
    rep(i, 1, a.size() - 1, 1) {
        std::cout << a[i] << " \n"[i == a.size() - 1];
    }
    return cout;
}
template<class T> std::istream &operator >> (std::istream &cin, matrix<T> &a) {
    rep(i, 1, a.size() - 1, 1) {
        rep(j, 1, a[i].size() - 1, 1) {
            cin >> a[i][j];
        }
    }
    return cin;
}
template<class T> std::ostream &operator << (std::ostream &cout, const matrix<T> &a) {
    if (a.empty()) {
        return cout;
    }
    rep(i, 1, a.size() - 1, 1) {
        rep(j, 1, a[i].size() - 1, 1) {
            cout << a[i][j] << " \n"[j == a[i].size() - 1];
        }
    }
    return cout;
}
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
int n;
std::vector<int> p;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> n;
    p.resize(n + 1, 0);
    rep(i, 1, n, 1) {
    	std::cin >> p[i];
    }

    std::map<int, std::vector<int>> hash;
    rep(i, 2, n, 1) {
    	int dif = std::abs(p[i] - p[i - 1]);
    	hash[dif].push_back(i);
    }

    std::vector<int> fa(n + 1); std::vector<int> sz(n + 1, 1); std::vector<int> rk(n + 1, 0);
    rep(i, 1, n, 1) {
    	fa[i] = i;
    }

    auto find = [&](auto &&find, int x) -> int {
    	if (x == fa[x]) {
    		return x;
    	} 
    	return fa[x] = find(find, fa[x]);
    };

    auto merge = [&](int x, int y) -> void {
    	int rx = find(find, x); int ry = find(find, y);
    	if (rx == ry) {
    		return ;
    	}
    	if (rk[rx] > rk[ry]) {
    		fa[ry] = rx;
    		sz[rx] += sz[ry];
    	} else if (rk[rx] == rk[ry]) {
    		fa[ry] = rx;
    		rk[rx] ++;
    		sz[rx] += sz[ry];
    	} else {
    		fa[rx] = ry;
    		sz[ry] += sz[rx];
    	}
    };

    auto f = [&](int x) -> ll {
    	x = find(find, x);
    	return (ll)sz[x] * (sz[x] - 1) / 2;
    }; //计算组合数C(sz[x], 2);

    ll cur = 0;
    std::vector<ll> ans; ans.push_back(-1);
    dep(i, n - 1, 1, 1) {
    	for (auto y : hash[i]) {
    		cur -= f(y);
    		cur -= f(y - 1);
    		merge(y, y - 1);
    		cur += f(y);
    	}
    	ans.push_back(cur);
    }
    // std::cout << ans.size() << "???\n";

    std::reverse(ans.begin() + 1, ans.end());
    rep(i, 1, n - 1, 1) {
    	std::cout << ans[i] << " \n"[i == n - 1];
    }
    /*太好了，这回只花998244353min就打完了！*/
/*
Test Sample

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