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
std::string s;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> n;
    std::cin >> s;

    bool ok = true;
    rep(i, 0, s.size() - 1) {
        if (s[i] == s[i + 1]) {
            ok = false;
            break;
        }
    }
    if (ok) {
        std::cout << "YES" << '\n';
        return ;
    }

    vec<int> c;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            c.push_back(i);
        }
    }

    if (c.size() > 1) {
        std::cout << "NO" << '\n';
        return ;
    }

    int i = c[0];
    bool ok1 = true, ok2 = true;

    if (i - 1 >= 0 and i + 1 < n) {
        if (s[i - 1] == s[i + 1]) {
            ok1 = false;
        }
    }

    if (i + 2 < n) {
        if (s[i] == s[i + 2]) {
            ok2 = false;
        }
    }

    if (ok1 or ok2) {
        std::cout << "YES" << '\n';
    } 
    else {
        std::cout << "NO" << '\n';
    }
    /*return AC*/
/*
Test Sample

6
abcdef

YES

6
abccde

YES

6
aabbcc

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