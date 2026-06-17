/*
* @Author: AlgoStruggler
* @Create Time: 2025-11-15 23:06:07
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
constexpr int MAXN = 2e5 + 10;
int n, m, k, q, v;
std::vector<int> a;
std::vector<int> w; std::vector<int> t;
int l, r;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
struct info {
    ll max;
};
std::vector<info> seg((MAXN << 2) + 10);
std::vector<ll> tag((MAXN << 2) + 10);

void update(ll id) {
    seg[id].max = std::max(seg[id * 2].max, seg[id * 2 + 1].max);
}

void build(ll id, ll l, ll r) {
    tag[id] = 0;
    if (l == r) {
        seg[id].max = a[l];
    } else {
        ll mid = l + r >> 1;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        update(id);
    }
}

void addtag(ll id, ll l, ll r, ll val) {
    tag[id] += val;
    seg[id].max += val;
}

void pushdown(ll id, ll l, ll r) {
    if (tag[id]) {
        ll mid = l + r >> 1;
        addtag(id * 2, l, mid, tag[id]);
        addtag(id * 2 + 1, mid + 1, r, tag[id]);
        tag[id] = 0;
    }
}

void modify(ll id, ll l, ll r, ll ql, ll qr, ll val) {
    if (l >= ql && r <= qr) {
        addtag(id, l, r, val);
        return;
    }
    pushdown(id, l, r);
    ll mid = l + r >> 1;
    if (ql <= mid) {
        modify(id * 2, l, mid, ql, qr, val);
    }
    if (qr > mid) {
        modify(id * 2 + 1, mid + 1, r, ql, qr, val);
    }
    update(id);
}

ll query(ll id, ll l, ll r, ll ql, ll qr) {
    if (ql <= l && r <= qr) {
        return seg[id].max;
    }
    pushdown(id, l, r);
    ll mid = l + r >> 1;
    ll res = -1e18;
    if (ql <= mid) {
        res = std::max(res, query(id * 2, l, mid, ql, qr));
    }
    if (qr > mid) {
        res = std::max(res, query(id * 2 + 1, mid + 1, r, ql, qr));
    }
    return res;
}
static inline void VioletEverGraden() {
    std::cin >> n >> m >> k >> q >> v;

    a.resize(n + 1);
    rep(i, 1, n, 1) {
        if (i == k) {
            continue;
        } else {
            std::cin >> a[i];
        }
    }

    w.resize(m + 1); t.resize(m + 1);
    rep(i, 1, m, 1) {
    	std::cin >> t[i] >> w[i];
    }
    std::vector<std::vector<int>> dp(1010, std::vector<int> (1010, 0));
    rep(i, 1, m, 1) {
        rep(j, 0, v, 1) {
            if (t[i] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - t[i]] + w[i]);
            }
        }
    }
    a[k] = dp[m][v];
    //std::cerr << a[k] << "??\n";

    build(1, 1, n);

    int __ = q;
    while (__ --) {
    	std::cin >> l >> r;
    	ll ans = query(1, 1, n, l, r);
    	std::cout << ans << '\n';
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
    //for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}