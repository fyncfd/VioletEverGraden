#define  _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O2")
#include "bits/stdc++.h"

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef __int128 i128;

using namespace std;
template <typename T> 
using pq = std::priority_queue<T>;
template<class T> 
using matrix = std::vector<std::vector<T>>;
template <typename T>
using vec = std::vector<T>;
template<typename T, typename U>
using ump = unordered_map<T, U>;

template<class T> concept Signed = std::is_signed_v<T>;
template<class T> concept Unsigned = std::is_unsigned_v<T>;
template<class T> concept Arithmetic = std::is_arithmetic_v<T>;

#define rep(i, l, r) for (int i = l; i <= r; i++)
#define red(i, l, r) for (int i = l; i >= r; i--)
#define lop(i, x) for (auto i : x)
#define all(x) a.begin(), a.end()
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
int n, m;
int x;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> n >> m;

    vec<int> k(n);
    rep(i, 1, n) {
        std::cin >> k[i];
    }

    ump<int, vec<int>> suma, sumb;
    for (int mk = 0; mk < (1 << n); mk ++) {
        int sum = 0;
        rep(i, 0, n - 1) {
            if (mk & (1 << i)) {
                sum += k[i];
            }
        }
        suma[sum].push_back(mk);
    }

    while (m --) {
        std::cin >> x;

        bool ok = false;
        for(auto &[p, q] : suma) {
            if (p == 0) {
                continue;
            }
            if (x % p != 0) {
                continue;
            }
            int sum2 = x / p;
            if (sumb.find(sum2) != sumb.end()) {
                ok = true;
                break;
            }
        }
        if (!ok) {
            std::cout << "No\n";
            continue;
        }
        std::cout << "Yes\n";

        for(auto[p, q] : suma) {
            if (p == 0) {
                continue;
            }
            if (x % p != 0) {
                continue;
            }
            int sum2 = x / p;
            if (sumb.find(sum2) != sumb.end()) {
                int la = __builtin_popcount(q[0]);
                int lb = __builtin_popcount(sumb[sum2][0]);
                int fd = 1;
                std::cout << la << " \n"[fd == 0] << lb << " \n"[fd == 1];

                rep(i, 0, n - 1) {
                    if (q[0] & (1 << i)) {
                        std::cout << k[i] << " \n"[i == n - 1];
                    }
                }

                rep(i, 0, n - 1) {
                    if (sumb[sum2][0] & (1 << i)) {
                        std::cout << k[i] << " \n"[i == n - 1];
                    }
                }
                break;
            }
        }
    }


    //debug();
/*
6 5
1 1 1 2 3 5
6
40
99
9
25

Yes
3 1
1 2 3
1
Yes
2 4
3 5
1 1 1 2
No
Yes
4 1
1 1 2 5
1
Yes
1 4
5
1 1 1 2
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