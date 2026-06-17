/*
* @Author: AlgoStruggler
* @Create Time: 2025-07-12 20:27:12
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
int a;
ll n;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> a;
    std::cin >> n;

    std::string str = std::to_string(n);
    int max = str.size();

    ll ans = 0;
    rep(d, 1, max, 1) {
        int half = (d + 1) / 2;
        ll bg = 1;
        for (int i = 0; i < half - 1; i++) {
            bg *= 10;
        }
        ll ed = bg * 10 - 1;

        rep(i, bg, ed, 1) {
            std::string s = std::to_string(i);
            std::string temp;
            if (d % 2 == 0) {
                std::string rev = s;
                std::reverse(rev.begin(), rev.end());
                temp = s + rev;
            } else {
                std::string rev = s.substr(0, s.size() - 1);
                std::reverse(rev.begin(), rev.end());
                temp = s + rev;
            }

            if (temp.size() > 18) {
                break;
            }

            ll cand;
            try {
                cand = stoll(temp);
            } catch (...) {
                break;
            }

            if (cand > n) {
                break;
            }

            std::vector<int> w;
            ll f = cand;
            while (f) {
                w.push_back(f % a);
                f /= a;
            }

            bool ok = true;
            int l = 0, r = w.size() - 1;
            while (l < r) {
                if (w[l] != w[r]) {
                    ok = false;
                    break;
                }
                l ++; r --;
            }

            if (ok) {
                ans += cand;
            }
        }
    }

    std::cout << ans << '\n';
    /*return AC*/
/*
Test Sample

8
1000

2155

8
999999999999

914703021014

6
999999999999

283958331810


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