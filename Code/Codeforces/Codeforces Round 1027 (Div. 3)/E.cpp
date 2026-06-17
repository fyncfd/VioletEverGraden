/*
* @Author: AlgoStruggler
* @Create Time: 2025-05-27 00:37:33
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
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;

//using namespace std;
//using namespace __gnu_pbds;
template <typename T> 
using pq = std::priority_queue<T>;
template<class T> 
using matrix = std::vector<std::vector<T>>;
template <typename T>
using vec = std::vector<T>;
template <class Key, class Value>
using ump = std::unordered_map<Key, Value>;
template <typename T>
using ust = std::unordered_set<T>;
//template <typename Key, typename Value>
//using hash = __gnu_pbds::gp_hash_table<Key, Value>;

template<class T> concept Signed = std::is_signed_v<T>;
template<class T> concept Unsigned = std::is_unsigned_v<T>;
template<class T> concept Arithmetic = std::is_arithmetic_v<T>;

#define all(x) x.begin() + 1, x.end()
#define LLA(x) (x).rbegin(), (x).rend()
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define red(i, l, r) for (int i = l; i >= r; i--)
#define lop(i, x) for (auto i : x)
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
matrix<int> g;
std::vector<ll> a;
std::vector<ll> h;
int u, v;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> n;
    a.resize(n);
    rep(i, 0, n - 1) {
        std::cin >> a[i];
    }
    g.assign(n + 1, std::vector<int>());

    int __ = n - 1;
    while (__ --) {
        std::cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    auto dfs = [&](auto &&self, int u, int p, ll x, ll y) -> void {
    	ll dif = a[u - 1] + std::max(0LL, y);
    	ll dif2 = -a[u - 1] + std::max(0LL, x);
    	h[u - 1] = std::max(a[u - 1], dif);

    	lop(v, g[u]) {
    		if (v == p) {
    			continue;
    		}
    		self(self, v, u, dif, dif2);
    	}
    };

    h.assign(n, 0);
    dfs(dfs, 1, 0, 0, 0); 
    rep(i, 0, n - 1) {
        std::cout<<h[i]<<(i == n - 1 ? "" : " ");
    }
    std::cout<<'\n';
    /*return AC*/
/*
Test Sample

2
5
4 5 2 6 7
1 2
3 2
4 3
5 1
6
1000000000 500500500 900900900 9 404 800800800
3 4
5 1
2 5
1 6
6 4

4 5 2 9 7
1000000000 1500500096 1701701691 199199209 404 800800800


*/
}
/*-------------------------------Author_Fd------------------------------------*/
static inline void VioletEverGraden();

auto __INIT__ = []() {
    std::cin.tie(nullptr) ->
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
};

signed main() {
#ifdef LOCAL
    freopen("A.in", "r", stdin);
#endif // LOCAL

    /*cout << fixed << setprecision();
    cerr << fixed << setprecision();*/


    __INIT__();

    int _ = 1;

    for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}