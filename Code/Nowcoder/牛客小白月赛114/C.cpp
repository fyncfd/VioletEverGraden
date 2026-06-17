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
constexpr int MAXN = 1e5 + 5;
int n, x;
std::vector<pii> a;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
/*int fa[MAXN];
void init() {
	rep(i, 1, n) {
		fa[i] = i;
	}
}

int find(int x) {
	if (fa[x] == x) {
		return fa[x];
	}
	return find(fa[x]);
}

void merge(int x, int y) {
	int rx = find(x);
	int ry = find(y);

	if (rx != ry) {
		fa[rx] = ry;
	}
}*/

static inline void VioletEverGraden() {
    std::cin >> n >> x;
    a.resize(n + 1);

    std::map<pii, bool> vis;
    rep(i, 1, n) {
    	std::cin >> a[i].first;
    	a[i].second = i;
    	vis[a[i]] = true;
    }

    int d = x;
    int num = 0;
    while (vis[a[x]]) {
    	x = a[x].first;
    	if (x == d) {
    		std::cout << "Yes\n";
    		return ;
    	}
    	num ++;
    	if (num > 1e5) {
    		break;
    	}
    } 

    std::cout << "No\n";
    /*return AC*/
/*
Test Sample

7 1
7 1 7 7 2 1 5

Yes

7 6
7 1 7 7 2 1 5

No


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

    //for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}