/*
* @Author: AlgoStruggler
* @Create Time: 2025-05-11 14:30:48
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
int n;
matrix<char> g;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> n;
    g.resize(3);
    rep(i, 1, 2) {
    	g[i].resize(n + 1);
    	rep(j, 1, n) {
    		std::cin >> g[i][j];
    	}
    }

    struct pii {
    	int fi; int se;
    };
    bool vis[3][MAXN] = { false };
    std::map<char, pii> hash;
    hash['>'] = {0, 1}; hash['<'] = {0, -1};
    auto dfs = [&](auto &&self, int x, int y) -> bool {
    	if (x == 2 and y == n) {
    		return true;
    	}
    	vis[x][y] = true;

    	rep(i, 1, 4) {
    		int nx = x + dx[i]; int ny = y + dy[i];
    		if  (nx > 2 or nx < 1 or ny > n or ny < 1 or vis[nx][ny]) {
    			continue;
    		}
/*    		self(self, nx, ny);*/
    		vis[nx][ny] = true;
    		nx = nx + hash[g[nx][ny]].fi; ny = ny + hash[g[nx][ny]].se;
    		if (!vis[nx][ny] >= 1 and nx <= 2 and ny >= 1 and ny <= n) {
    			vis[nx][ny] = true;
    			/*self(self, nx, ny);*/
    			if (self(self, nx, ny)) {
    				return true;
    			}
/*    			vis[nx][ny] = false;*/
    		}
    	}

    	return false;
    };

    bool ok = dfs(dfs, 1, 1);

    if (ok) {
    	std::cout << "YES\n";
    	return ;
    }
    std::cout << "NO\n";
    /*return AC*/
/*
Test Sample

4
4
>><<
>>><
2
><
><
4
>>><
>><<
6
>><<><
><>>><

YES
YES
NO
YES


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

    for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}