/*
* @Author: AlgoStruggler
* @Create Time: 2025-07-31 23:40:52
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

using namespace std;
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

/*-------------------------------MY_CODE_BEGIN--------------------------------*/
struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n+1);
        for (int i=1; i<=n; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        parent[y] = x;
    }
};
static inline void VioletEverGraden() {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> edge;
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        edge.push_back(make_tuple(a, b, i+1));
    }

    sort(edge.begin(), edge.end(), [](const tuple<int,int,int>& x, const tuple<int,int,int>& y) {
        if (get<1>(x) != get<1>(y)) {
            return get<1>(x) < get<1>(y);
        }
        return get<0>(x) < get<0>(y);
    });

    int max_v = 2 * n;
    DSU dsu(max_v);
    vector<bool> covered(max_v + 1, false);
    vector<int> pp;

    for (const auto& e : edge) {
        int a = get<0>(e);
        int b = get<1>(e);
        int idx = get<2>(e);
        int L = a;
        int R = b - 1;

        int count = 0;
        for (int x = L; x <= R; x++) {
            if (!covered[x]) {
                count++;
            }
        }

        if (count > 0 && dsu.find(a) != dsu.find(b)) {
            pp.push_back(idx);
            for (int x = L; x <= R; x++) {
                if (!covered[x]) {
                    covered[x] = true;
                }
            }
            dsu.merge(a, b);
        }
    }

    sort(pp.begin(), pp.end());
    cout << pp.size() << "\n";
    if (pp.size() > 0) {
        for (int i = 0; i < pp.size(); i++) {
            if (i > 0) cout << " ";
            cout << pp[i];
        }
        cout << "\n";
    }
    /*太好了，这回只花998244353min就打完了！*/
/*
Test Sample

2
1
1 2
4
1 2
2 3
1 3
3 5

1
1
3
1 3 4


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