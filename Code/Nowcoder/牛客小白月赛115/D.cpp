/*
* @Author: AlgoStruggler
* @Create Time: 2025-04-25 19:47:27
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
#define pb push_back
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define red(i, l, r) for (int i = l; i >= r; i--)
#define lop(i, x) for (auto& i : x)
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
std::vector<std::string> s; 
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> n;
    s.resize(n);
    std::vector<int> len(n);
    rep(i, 0, n - 1) {
    	std::cin >> s[i];
    	len[i] = s[i].size();
    }

    auto sgcd = [](int a, int b) {
    	while (b) {
    		a %= b;
    		std::swap(a, b);
    	}
    	return a;
    };

/*    auto with = [&sgcd](std::vector<int>& arr) {
        int g = arr[0];
        return g;
    };*/

    auto calc = [&sgcd](const std::vector<int>& arr) {
        int g = arr[0];
        for (int num : arr) {
            g = sgcd(g, num);
        }
        return g;
    };

    auto fac = [](int g) {
        std::vector<int> fa;
        for (int i = 1; i * i <= g; ++i) {
            if (g % i == 0) {
                fa.pb(i);
                if (i != g / i) {
                    fa.pb(g / i);
                }
            }
        }
        sort(fa.begin(), fa.end());
        return fa;
    };

    int g = calc(len);
    std::vector<int> fa = fac(g);

    int ans = INF;
    lop(d, fa) {
        int sum = 0;
        lop(l, len) {
        	sum += l / d;
        }

        std::vector<std::vector<int>> cnt(d, std::vector<int>(26, 0));
        for (const std::string& s : s) {
            size_t len = s.size();
            rep(j, 0, len - 1) {
                int p = j % d;
                cnt[p][s[j] - 'a']++;
            }
        }

        int temp = 0;
        rep(p, 0, d - 1) {
            int max = *max_element(cnt[p].begin(), cnt[p].end());
            temp += sum - max;
        }

        if (temp < ans) {
        	ans = temp;
        }
    }

    std::cout << ans << '\n';
    /*return AC*/
/*
Test Sample

2
abac
bc

2

3
aba
ab
bc

4


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

    //\for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}