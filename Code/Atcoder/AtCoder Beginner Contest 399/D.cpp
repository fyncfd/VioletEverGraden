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
    vec<int> p(2 * n);
    rep(i, 0, 2 * n - 1) {
        cin >> p[i];
    }

    ump<int, pair<int, int>> hash;
    rep(i, 0, 2 * n - 1) {
        int x = p[i];
        if (hash.count(x)) {
            int a = hash[x].first;
            int b = i;
            if (a > b) swap(a, b);
            hash[x] = {a, b};
        } else {
            hash[x] = {i, -1};
        }
    }

    vec<int> s;
    for (auto& [x, p] : hash) {
        int a = p.first;
        int b = p.second;
        if (b - a != 1) {
            s.push_back(x);
        }
    }

    sort(s.begin(), s.end());

    map<pair<int, int>, int> pair_map;
    for (int x : s) {
        pair_map[hash[x]] = x;
    }

    int count = 0;
    for (int i = 0; i < s.size(); ++i) {
        int a = s[i];
        auto [a1, a2] = hash[a];
        vec<pair<int, int>> temp = {
            {a1 + 1, a2 + 1},
            {a1 - 1, a2 - 1},
            {a1 + 1, a2 - 1},
            {a1 - 1, a2 + 1}
        };

        for (auto [b1, b2] : temp) {
            if (b1 < 0 || b2 >= 2 * n) continue;
            if (b1 >= b2) continue;
            auto it = pair_map.find({b1, b2});
            if (it != pair_map.end()) {
                int b = it->second;
                if (a < b) {
                    count++;
                }
            }
        }
    }

    std::cout << count << '\n';
    /*return AC*/
/*
Test Sample

3
3
1 2 3 3 1 2
4
1 1 2 2 3 3 4 4
5
1 2 3 4 5 1 2 3 4 5

1
0
4


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

    for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}