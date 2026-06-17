/*
* @Author: AlgoStruggler
* @Create Time: 2026-01-09 19:37:18
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
constexpr int MAXN = 1e5 + 5;
int n; ll k;
ll a[MAXN];
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
int ls[MAXN], rs[MAXN];
std::map<ll, std::vector<pii>> memo;
std::map<std::pair<ll, int>, int> hash;

inline ll encode(int l, int r) {
    return ((ll)l << 32) | r;
}

int Split(int L, int R) {
    ll dif = a[L] ^ a[R];
    if (dif == 0) {
    	return L;
    }
    int msb = 63 - __builtin_clzll(dif);
    int low = L; int high = R;
    int ans = R;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if ((a[mid] >> msb) & 1) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans - 1;
}

std::vector<pii> f(int L, int R) {
    if (L > R) {
    	return {};
    }
    if (L == R) {
    	return {{L, 0}};
    }
    ll key = encode(L, R);
    if (memo.count(key)) {
    	return memo[key];
    }
    
    int mid = Split(L, R);
    auto l = f(L, mid); auto r = f(mid + 1, R);
    
    std::vector<pii> res;
    
    for (auto &u : l) {
        if (u.se & 2) {
        	continue;
        }
        for (auto &v : r) {
            if ((a[u.fi] ^ a[v.fi]) <= k) {
                hash[{key, u.fi}] = v.fi;
                res.push_back({u.fi, u.se | 2});
                break;
            }
        }
    }
    
    for (auto &v : r) {
        if (v.se & 1) {
        	continue;
        }
        for (auto &u : l) {
            if ((a[v.fi] ^ a[u.fi]) <= k) {
                hash[{key, v.fi}] = u.fi;
                res.push_back({v.fi, v.se | 1});
                break;
            }
        }
    }
    
    return memo[key] = res;
}

void build(int L, int R, int rt) {
    if (L == R) {
    	return;
    }
    int mid = Split(L, R);
    ll key = encode(L, R);
    int son = hash[{key, rt}];
    
    if (rt <= mid) {
        rs[rt] = son;
        build(L, mid, rt); build(mid + 1, R, son);
    } else {
        ls[rt] = son;
        build(L, mid, son); build(mid + 1, R, rt);
    }
}

static inline void VioletEverGraden() {
    std::cin >> n >> k;
    rep(i, 1, n, 1) {
        std::cin >> a[i];
        ls[i] = 0;
        rs[i] = 0;
    }
    memo.clear();
    hash.clear();
    auto rt = f(1, n);
    
    if (rt.empty()) {
        std::cout << "No\n";
    } else {
        std::cout << "Yes\n";
        int root = rt[0].fi;
        build(1, n, root);
        rep(i, 1, n, 1) {
            std::cout << ls[i] << " " << rs[i] << '\n';
        }
    }
    /*太好了，这回只花998244353min就打完了！*/
/*
Test Sample

2
5 5
1 2 3 4 5
5 8
1 2 3 4 8

Yes
0 2
0 3
0 0
1 5
0 0
No


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