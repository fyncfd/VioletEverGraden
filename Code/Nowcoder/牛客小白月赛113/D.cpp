#define  _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O2")
#include "bits/stdc++.h"
//#include <ext/pb_ds/assoc_container.hpp>

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef __int128 i128;

using namespace std;
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

#define all(x) a.begin(), a.end()
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define red(i, l, r) for (int i = l; i >= r; i--)
#define lop(i, x) for (auto i : x)
/*------------------------------SORT_AND_UNIQUE-------------------------------*/
//#define int long long
const double eps = 1e-9;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr ll mod = 998244353;
constexpr ll MOD = 1e9 + 7;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
constexpr int MAXN = 0;
int n;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
	std::cin >> n;
    vec<ll> arr(n);
    rep(i, 0, n - 1) {
        std::cin >> arr[i];
    }

    bool ok1 = true;
    rep(i, 1, n - 1) {
        if (arr[i] != arr[0]) {
            ok1 = false;
            break;
        }
    }
    if (ok1) {
        std::cout << 0 << '\n';
        return ;
    }

    bool ok2 = false;
    for (ll x : arr) {
        if (x == 0) {
            ok2 = true;
            break;
        }
    }
    if (!ok2) {
        cout << -1 << '\n';
        return ;
    }
    sort(arr.begin(), arr.end());
    ll ma = arr.back();

    ll s = 0;
    int r = 0;

    while (true) {
        int k = upper_bound(arr.begin(), arr.end(), s) - arr.begin();
        ll mex = 1;
        rep(i, k, n - 1) {
            ll val = arr[i] - s;
            if (val < mex) {
                continue;
            } 
            else if (val == mex) {
                mex ++;
            } 
            else {
                break;
            }
        }

        if (mex == 0) {
            std::cout << -1 << '\n';
            return ;
        }

        s += mex;
        r ++;

        if (s >= ma) {
            cout << r << '\n';
            return ;
        }
    }
    /*return AC*/
/*
Test Sample

6
0 1 2 3 4 5

1

5
3 1 2 4 5

-1

6
0 1 3 4 7 9

5


*/
}
/*-------------------------------Author_Fd------------------------------------*/
void TestArea();
void TimeTest();
static inline void VioletEverGraden();

signed main() {
#ifdef LOCAL
    freopen("A.in", "r", stdin);
#endif // LOCAL

    /*cout << fixed << setprecision();
    cerr << fixed << setprecision();*/

    std::cin.tie(nullptr) -> 
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);

    int _ = 1;

    //for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}