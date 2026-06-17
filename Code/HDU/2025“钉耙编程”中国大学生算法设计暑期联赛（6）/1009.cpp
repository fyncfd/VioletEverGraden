/*
* @Author: AlgoStruggler
* @Create Time: 2025-08-04 15:07:20
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
int n;
std::vector<ll> a;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    int T;
    cin >> T;
    vector<ll> res;

    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        if (n <= 2) {
            res.push_back(0);
            continue;
        }

        vector<int> left(n), right(n);
        for (int i = 0; i < n; ++i) {
            left[i] = i - 1;
            right[i] = i + 1;
        }
        left[0] = -1;
        right[n - 1] = -1;

        vector<bool> rem(n, false);
        priority_queue<pair<int, int>> heap;

        for (int i = 0; i < n; ++i) {
            if (left[i] != -1 && right[i] != -1) {
                int energy = max(a[left[i]], a[right[i]]);
                heap.push({energy, i});
            }
        }

        ll sum = 0;

        while (!heap.empty()) {
            auto current = heap.top();
            heap.pop();
            int energy = current.first;
            int i = current.second;

            if (rem[i]) {
                continue;
            }
            if (left[i] == -1 || right[i] == -1) {
                rem[i] = true;
                continue;
            }

            int cur = max(a[left[i]], a[right[i]]);
            if (energy != cur) {
                heap.push({cur, i});
                continue;
            }

            sum += cur;
            rem[i] = true;
            int l = left[i];
            int r = right[i];

            if (l != -1) {
                right[l] = r;
            }
            if (r != -1) {
                left[r] = l;
            }

            if (l != -1 && !rem[l] && left[l] != -1 && right[l] != -1) {
                int temp = max(a[left[l]], a[right[l]]);
                heap.push({temp, l});
            }
            if (r != -1 && !rem[r] && left[r] != -1 && right[r] != -1) {
                int temp = max(a[left[r]], a[right[r]]);
                heap.push({temp, r});
            }
        }

        res.push_back(sum);
    }

    for (ll res : res) {
        cout << res << '\n';
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