/*
* @Author: AlgoStruggler
* @Create Time: 2025-06-29 19:06:21
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
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;

//using namespace std;
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

#define all(x) x.begin() + 1, x.end()
#define LLA(x) (x).rbegin(), (x).rend()
#define rep(i, l, r, x) for (decltype(l) i = (l); i <= (r); i += (x))
#define dep(i, l, r, x) for (decltype(l) i = (l); i >= (r); i -= (x))
#define lop(i, x) for (auto &i : x)
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
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> n;

    std::vector<std::vector<int>> p;
    rep(m, 1, n, 1) {
        int temp = m;

        std::function<void(std::vector<int>)> dfs = [&](std::vector<int> f) {
            int sum = accumulate(f.begin(), f.end(), 0);
            int k = f.size();

            if (sum > n) {
            	return;
            }

            if (k == temp) {
                if (sum == n) {
                	p.push_back(f);
                }
                return;
            }

            int thiz = temp - (k + 1);
            int max = (n - sum) - thiz;
            int pre = k == 0 ? 0 : f.back();

            rep(x, 1, max, 1) {
                if (x == pre) {
                	continue;
                }

                f.push_back(x);
                dfs(f);
                f.pop_back();
            }
        };

        std::vector<int> f;
        dfs(f);
    }

    std::sort(p.begin(), p.end(), [&](std::vector<int> a, std::vector<int> b) {
    	return a < b;
    });

    lop(arr, p) {
        rep(i, 0, arr.size() - 1, 1) {
            std::cout << arr[i] << " \n"[i == arr.size() - 1];
        }
    }
    /*return AC*/
/*
Test Sample

3

1 2
2 1
3


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

    /*cout << std::fixed << std::setprecision(9);
    cerr << std::fixed << std::setprecision(9);*/


    __INIT__();

    int _ = 1;

    //for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}