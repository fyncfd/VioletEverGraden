/*
* @Author: AlgoStruggler
* @Create Time: 2025-04-24 23:07:18
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
#define pb push_back
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define red(i, l, r) for (int i = l; i >= r; i--)
#define lop(i, x) for (auto i : x)
/*------------------------------SORT_AND_UNIQUE-------------------------------*/
#define int long long
const double eps = 1e-9;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3f;
constexpr ll mod = 998244353;
constexpr ll MOD = 1e9 + 7;
int dx[] = {0, 0, 1, 0, -1 };
int dy[] = {0, -1, 0, 1, 0 };
constexpr int MAXN = 0;
int n, m;
std::vector<ll> a;
std::vector<ll> b;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> n >> m;
    a.resize(n);
    b.resize(m);
    rep(i, 0, n - 1) {
    	std::cin >> a[i];
    }
    rep(i, 0, m - 1) {
    	std::cin >> b[i];
    }

    std::vector<int> pre(m + 1, -1);
    rep(i, 1, m) {
        int pos = pre[i - 1] + 1;
        while (pos < n and a[pos] < b[i - 1]) {
            pos ++;
        }
        if (pos < n) {
            pre[i] = pos;
        } 
        else {
            rep(j, i, m) {
                pre[j] = n;
            }
            break;
        }
    }

    std::vector<int> suf(m + 1, n);
    rep(i, 1, m) {
        int pos = suf[i - 1] - 1;
        int temp = b[m - i];
        while (pos >= 0 and a[pos] < temp) {
            pos --;
        }
        if (pos >= 0) {
            suf[i] = pos;
        } 
        else {
            rep(j, i, m) {
                suf[j] = -1;
            }
            break;
        }
    }

    if (pre[m] < n) {
        std::cout << 0 << '\n';
        return ;
    }

    int ans = INF;
    rep(j, 0, m) {
        if (j == 0) {
            if (m - 1 >= 0 and suf[m - 1] != -1) {
                ans = std::min(ans, b[0]);
            }
        } 
        else if (j == m) {
            if (pre[m - 1] < n) {
                ans = std::min(ans, b[m - 1]);
            }
        } 
        else {
            int res = m - j - 1;
            if (res < 0) {
            	continue;
            }
            if (pre[j] < n and res <= m and suf[res] != -1) {
                if (pre[j] < suf[res]) {
                    ans = std::min(ans, b[j]);
                }
            }
        }
    }

    if (ans == INF) {
        std::cout << -1 << '\n';
        return ;
    }
    std::cout << ans << '\n';
    /*return AC*/
/*
Test Sample

7
9 5
3 5 2 3 3 5 8 1 2
4 6 2 4 6
6 3
1 2 6 8 2 1
5 4 3
5 3
4 3 5 4 3
7 4 5
6 3
8 4 2 1 2 5
6 1 4
5 5
1 2 3 4 5
5 4 3 2 1
6 3
1 2 3 4 5 6
9 8 7
5 5
7 7 6 7 7
7 7 7 7 7

6
3
7
0
-1
-1
7


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