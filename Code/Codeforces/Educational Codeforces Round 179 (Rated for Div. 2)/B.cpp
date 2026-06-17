/*
* @Author: AlgoStruggler
* @Create Time: 2025-06-03 22:51:20
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
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define red(i, l, r) for (int i = l; i >= r; i--)
#define lop(i, x) for (auto i : x)
/*------------------------------SORT_AND_UNIQUE-------------------------------*/
//#define int long long
const double eps = 1e-9;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3f;
constexpr ll mod = 998244353;
constexpr ll MOD = 1e9 + 7;
int dx[] = {0, 0, 1, 0, -1 };
int dy[] = {0, -1, 0, 1, 0 };
constexpr int MAXN = 2e5 + 10;
int n, m;
int w, l, h;
ll fib[MAXN];
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> n >> m;

    int __ = m;
    while (__ --) {
    	std::cin >> w >> l >> h;

    	int p1 = fib[n]; int p2 = fib[n - 1] + fib[n];
    	if (w >= p2) {
    		if (l >= p1 and h >= p1) {
    			std::cout << '1';
    		} else {
    			std::cout << '0';
    		}
    	} else if (l >= p2) {
    		if (w >= p1 and h >= p1) {
    			std::cout << '1';
    		} else {
    			std::cout << '0';
    		}
    	} else if (h >= p2) {
    		if (w >= p1 and l >= p1) {
    			std::cout << '1';
    		} else {
    			std::cout << '0';
    		}
    	} else {
    		std::cout << '0';
    	}
    }
    	std::cout << std::endl;
    /*return AC*/
/*
Test Sample

2
5 4
3 1 2
10 10 10
9 8 13
14 7 20
2 6
3 3 3
1 2 1
2 1 2
3 2 2
2 3 1
3 2 4

0010
100101


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

    /*cout << std::fixed << std::setprecision();
    cerr << std::fixed << std::setprecision();*/


    __INIT__();

    //ll fib[MAXN] = {0};
    //auto init = [&]() {
    	fib[1] = 1; fib[2] = 2;
    	rep(i, 3, MAXN) {
    		fib[i] = fib[i - 1] + fib[i - 2];
    	}
    	//return ;
    //}();

    int _ = 1;

    for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}