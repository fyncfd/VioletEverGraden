/*
* @Author: AlgoStruggler
* @Create Time: 2025-07-24 12:15:36
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
int n, k; ll c;
std::vector<ll> a;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> n >> k >> c;
    a.resize(n + 1);
    rep(i, 1, n, 1) {
    	std::cin >> a[i];
    }

/*    std::vector<int> p; p.push_back(-1);
    std::vector<int> q; q.push_back(-1);
    rep(i, 1, k, 1) {
    	p.push_back(a[i]);
    }
    rep(i, k + 1, n, 1) {
    	q.push_back(a[i]);
    }

    std::sort(p.begin() + 1, p.end(), [&](ll a, ll b) -> bool {
    	return a < b;
    });
    std::sort(a.begin() + 1, a.end(), [&](ll a, ll b) -> bool {
    	return a > b;
    });

    ll ans = 0;
    rep(i, 1, k, 1) {
    	ans += p[i];
    }

    int pos = 1;
    while (true) {
    	if (p[pos] - q[pos] >= c) {
    		ans += p[pos] - q[pos] - c;
    		pos ++;
    	} else {
    		break;
    	}
    }*/

    if (k == 0) {
    	std::cout << 0 << '\n';
    	return ;
    }

    std::priority_queue<ll> heap;
    ll ans = 0; int id = n;
    
    dep(t, k, 1, 1) {
        while (id >= t) {
            heap.push(a[id] - c * id);
            id --;
        }
        if (heap.empty()) {
            break;
        }
        ll top = heap.top();
        heap.pop();
        ans += top + c * t;
    }

   	std::cout << ans << '\n';
    /*return AC*/
/*
Test Sample

3 2 1
1 3 5

6

3 2 2
1 3 5

4

4 2 1
2 3 5 6

7

7 3 2
2 1 3 6 10 9 7

10


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