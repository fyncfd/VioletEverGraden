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
int q;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> q;

    bool ok = true;
    vec<int> all;

    rep(i, 0, q - 1) {
        int k;
        cin >> k;
        vec<int> arr(k);
        rep(j, 0, k - 1) {
            cin >> arr[j];
        }
        rep(j, 1, k - 1) {
            if (arr[j] <= arr[j-1]) {
                ok = false;
            }
        }

        all.insert(all.end(), arr.begin(), arr.end());
    }

    if (!ok) {
        std::cout << "NO\n";
        return ;
    }

    std::sort(all.begin(), all.end());

    bool can = false;
    for (int i = 1; i < all.size(); ++i) {
        if (all[i] == all[i-1]) {
            can = true;
            break;
        }
    }

    if (can) {
        std::cout << "NO\n";
        return ;
    }

    int n = all.size();
    if (n == 0) {
        cout << "YES\n";
        return ;
    }

    int mi = all[0];
    int ma = all.back();

    if (ma - mi + 1 == n) {
        std::cout << "YES\n";
    } 
    else {
        std::cout << "NO\n";
    }
    /*return AC*/
/*
Test Sample

3
3 2 5 6
2 3 7
4 4 8 9 10

YES

3
1 5
1 4
1 3

YES

3
3 1 2 3
3 4 5 6
1 1

NO

2
3 2 4 5
2 1 6

NO


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