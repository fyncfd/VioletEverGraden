/*
* @Author: AlgoStruggler
* @Create Time: 2025-05-18 19:16:31
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
//typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;

using namespace std;
//using namespace __gnu_pbds;
/*template <typename T> 
using pq = std::priority_queue<T>;*/
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
constexpr int MAXN = 2e5 + 10;
int n, k;
std::vector<ll> a;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> n >> k;
    a.resize(n);
    rep(i, 0,  n - 1) {
        std::cin >> a[i];
    }
    if (k == 0) {
        rep(i, 0,  n - 1) {
            std::cout << a[i] << " \n"[i == n - 1];
        }
        return ;
    }

    if (n == 1) {
        std::cout << a[0] << '\n';
        return ;
    }

    bool vis[MAXN] = {true};
    std::priority_queue<pll> pq;
    rep(i, 1, n - 1) {
        pq.emplace(a[i], i);
    }
    int pos = k;
    while (pos > 0 && !pq.empty()) {
        auto [val, idx] = pq.top();
        pq.pop();
        if (!vis[idx]) continue;
        a[0] += val;
        vis[idx] = false;
        pos --;
    }

    std::vector<ll> ans;
    ans.push_back(a[0]);
    for (int i = 1; i < n; ++i) {
        if (vis[i]) {
            ans.push_back(a[i]);
        }
    }
    for (size_t i = 0; i < ans.size(); i ++) {
        std::cout << ans[i] << " \n"[i == ans.size() - 1];
    }
    /*return AC* /
/*
Test Sample

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

        int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        if (k == 0) {
            for (int i = 0; i < n; ++i) {
                cout << a[i] << " \n"[i == n - 1];
            }
            continue;
        }
        if (n == 1) {
            cout << a[0] << '\n';
            continue;
        }
        vector<bool> valid(n, true);
        priority_queue<pair<ll, int>> pq;
        for (int i = 1; i < n; ++i) {
            pq.emplace(a[i], i);
        }
        int ops = k;
        while (ops > 0 && !pq.empty()) {
            auto [val, idx] = pq.top();
            pq.pop();
            if (!valid[idx]) continue;
            a[0] += val;
            valid[idx] = false;
            ops--;
        }
        vector<ll> res;
        res.push_back(a[0]);
        for (int i = 1; i < n; ++i) {
            if (valid[i]) {
                res.push_back(a[i]);
            }
        }
        for (size_t i = 0; i < res.size(); ++i) {
            cout << res[i] << " \n"[i == res.size() - 1];
        }
    }

    return 0;
}