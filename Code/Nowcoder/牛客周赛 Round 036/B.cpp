/*
* @Author: AlgoStruggler
* @Create Time: 2025-05-27 23:01:17
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
int n, m; ll x;
matrix<ll> g;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> n >> m >> x;
    g.resize(n + 1, std::vector<ll> (m + 1));
    rep(i, 1, n) {
    	rep(j, 1, m) {
    		std::cin >> g[i][j];
    	}
    }

    ll sum = 0;
    rep(i, 1, n) {
        rep(j, 1, m) {
            sum += g[i][j];
        }
    }

    if(sum != x){
        std::cout << "wrong answer\n";
    } else {
        std::set<ll> l, r;
        rep(i, 1, n) {
            ll res = g[i][1];
            rep(j, 2, m) {
                res ^= g[i][j];
            }
            l.insert(res);
        }
        rep(i, 1, m) {
            ll res = g[1][i];
            rep(j, 2, n) {
                res ^= g[j][i];
            }
            l.insert(res);
        }

        if(l.size() != 1){
            std::cout << "wrong answer\n";
        } else {
        	std::cout << "accepted\n";
        }
    }
    /*return AC*/
/*
Test Sample

4 4 14
1 2 3 0
1 2 2 1
0 0 1 1
0 0 0 0

accepted

4 4 4
1 1 1 1
0 0 0 0
0 0 0 0
0 0 0 0

wrong answer

4 4 4
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1

wrong answer


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

    //for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}