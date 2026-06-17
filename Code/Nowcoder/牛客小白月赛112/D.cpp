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
using ump = unordered_map<T, U>

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
int n;
int u, v;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    cin >> n;
    vec<int> deg(n + 1, 0);
    rep(i, 0, n - 2) {
        std::cin >> u >> v;
        deg[u]++;
        deg[v]++;
    }
    
    int ma = 0;
    rep(i, 1, n) {
        ma = std::max(ma, deg[i]);
    }
    
    int cnt = 0;
    rep(i, 1, n) {
        if (deg[i] == ma) {
            cnt++;
        }
    }
    
    int se = -1;
    rep(i, 1, n) {
        if (deg[i] < ma) {
            se = std::max(se, deg[i]);
        }
    }
    
    int mi = n + 1;
    int ans = -1;
    rep(u, 1, n) {
        int temp;
        if (deg[u] < ma) {
            temp = std::max(deg[u], ma - 1);
        } 
        else {
            if (cnt > 1) {
                temp = ma;
            } 
            else {
                int tmp = (se == -1) ? 0 : se - 1;
                temp = std::max(ma, tmp);
            }
        }
        
        if (temp < mi or (temp == mi and u < ans)) {
            mi = temp;
            ans = u;
        }
    }
    
    int x = 1;
    cout << mi << " \n"[x == 0] << ans << " \n"[x == 1];
    //debug();
/*

4
3 1
2 3
3 4

2 1

3
1 2
1 3

1 2


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