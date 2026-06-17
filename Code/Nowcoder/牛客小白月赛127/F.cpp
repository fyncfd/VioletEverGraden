/* 
* @Author: AlgoStruggler
* @Create Time: 2026-01-16 19:52:22
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
#define debug(x) std::cerr << #x << " = " << x << '\n'
#define debug2(x, y) std::cerr << #x << " = " << x << ", " << #y << " = " << y << '\n'


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
constexpr int MAXN = 0;
int n; ll k;
std::vector<ll> a;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> n >> k;
    a.resize(n + 1);
    rep(i, 1, n, 1) {
        std::cin >> a[i];
    }

    std::vector<int> v0; std::vector<int> v1; std::vector<int> v2;
    rep(i, 1, n, 1) {
        if (a[i] % 2 != 0) {
            v0.push_back(i);
        } else if (a[i] % 4 == 0) {
            v2.push_back(i);
        } else {
            v1.push_back(i);
        }
    }

    if (n == 1) {
        std::cout << 1 << '\n';
        return;
    }

    struct Edge {
        int u, v;
    };
    std::vector<Edge> G;
    int rt = -1;

    if (v2.empty()) {
        if (!v0.empty()) {
            std::cout << -1 << '\n';
            return;
        }
        rt = v1[0];
        std::vector<int> q = { rt };
        std::vector<int> son = {0};
        int head = 0;
        rep(i, 1, (int)v1.size() - 1, 1) {
            while (head < (int)q.size() and son[head] >= k) {
                head ++;
            }
            if (head >= (int)q.size()) {
                std::cout << -1 << '\n';
                return;
            }
            int u = q[head]; int v = v1[i];
            G.push_back({u, v});
            son[head] ++;
            q.push_back(v);
            son.push_back(0);
        }
    } else {
        bool ok1 = false;
        bool ok2 = false; 

        if (v0.empty()) {
            ok2 = (n - 1 <= (ll)v2.size() * k);
        } else {
            ok1 = (v2.size() <= k and (v2.size() + v1.size() <= (ll)v2.size() * k));
            ok2 = (n - 1 <= (ll)v2.size() * k);
        }

        if (ok1) {
            rt = v0[0];
            std::vector<int> q;
            std::vector<int> son;
            int head = 0;

            q.push_back(rt);
            son.push_back(0);

            for (int id : v2) {
                while (head < (int)q.size() and son[head] >= k) {
                    head++;
                }
                if (head >= (int)q.size()) {
                    std::cout << -1 << '\n';
                    return;
                }
                G.push_back({q[head], id});
                son[head]++;
                q.push_back(id);
                son.push_back(0);
            }

            for (int id : v1) {
                while (head < (int)q.size() and son[head] >= k) {
                    head++;
                }
                if (head >= (int)q.size()) {
                    std::cout << -1 << '\n';
                    return;
                }
                G.push_back({q[head], id});
                son[head]++;
                q.push_back(id);
                son.push_back(0);
            }

            for (int i = 1; i < (int)v0.size(); i++) {
                while (head < (int)q.size() and son[head] >= k) {
                    head++;
                }
                if (head >= (int)q.size()) {
                    std::cout << -1 << '\n';
                    return;
                }
                G.push_back({q[head], v0[i]});
                son[head]++;
            }
        } else if (ok2) {
            rt = v2[0];
            std::vector<int> q;
            std::vector<int> son;
            int head = 0;

            q.push_back(rt);
            son.push_back(0);

            for (int i = 1; i < (int)v2.size(); i++) {
                while (head < (int)q.size() and son[head] >= k) {
                    head++;
                }
                if (head >= (int)q.size()) {
                    std::cout << -1 << '\n';
                    return;
                }
                G.push_back({q[head], v2[i]});
                son[head]++;
                q.push_back(v2[i]);
                son.push_back(0);
            }

            for (int id : v0) {
                while (head < (int)q.size() and son[head] >= k) {
                    head++;
                }
                if (head >= (int)q.size()) {
                    std::cout << -1 << '\n';
                    return;
                }
                G.push_back({q[head], id});
                son[head]++;
            }

            for (int id : v1) {
                while (head < (int)q.size() and son[head] >= k) {
                    head++;
                }
                if (head >= (int)q.size()) {
                    std::cout << -1 << '\n';
                    return;
                }
                G.push_back({q[head], id});
                son[head]++;
                q.push_back(id);
                son.push_back(0);
            }
        } else {
            std::cout << -1 << '\n';
            return;
        }
    }

    std::cout << rt << '\n';
    for (auto &e : G) {
        std::cout << e.u << ' ' << e.v << '\n';
    }
    /*太好了，这回只花998244353min就打完了！*/
/*
Test Sample

6
1 1
1
4 3
1 2 3 4
4 1
1 2 3 4
5 1
2 6 2 1 2
6 2
2 2 2 2 2 2
3 1
1 4 3

1
1
1 4
1 3
1 2
-1
-1
1
1 2
1 3
2 4
2 5
3 6
1
1 2
2 3

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