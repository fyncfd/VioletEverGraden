/*
* @Author: AlgoStruggler
* @Create Time: 2025-05-22 17:07:02
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
#define int long long
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
std::vector<int> prime,isprime(7e6 + 1,1);
void seive(){
	prime.push_back(0);
    for(int i = 2; i <= 7e6; i++){
        if(!isprime[i]) { 
        	continue;
        }
        prime.push_back(i);
        for(int j = i; j <= 7e6; j += i){
            isprime[j] = 0;
        }
    }
}
static inline void VioletEverGraden() {
    std::cin >> n;
    a.resize(n + 1);
    rep(i, 1, n) {
    	std::cin >> a[i];
    }

    std::sort(a.begin() + 1, a.end(), [&](int a, int b) {
        return a > b;
    });
    ll sum1 = 0; ll sum2 = 0;
    ll ans = 0;
    rep(i, 1, n) {
        sum1 += a[i];
        sum2 += prime[i];

        if (sum2 < sum1) {
            ans = n - i;
        }
    }

    std::cout << ans << '\n';
    /*return AC*/
/*
Test Sample

5
3
5 5 5
4
2 3 2 4
1
3
3
2 100 2
5
2 4 2 11 2

0
2
0
0
1


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

    seive();

    for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}