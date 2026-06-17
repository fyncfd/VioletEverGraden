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
constexpr int MAXN = 0;
struct node {
	int v;
	int id;
};
std::vector<node> p(4);
std::vector<int> a;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
	int n = 0;
	rep(i, 1, 3) {
		std::cin >> p[i].v;
		p[i].id = i;
		n += p[i].v;
	}
	a.resize(n + 1);
	rep(i, 1, n) {
		std::cin >> a[i];
	}

	std::sort(p.begin() + 1, p.end(), [](node a, node b) {
		return a.v > b.v;
	});
	
	if (p[1].v == p[2].v and p[2].v == p[3].v) {
		rep(i, 1, n) {
			if (a[i] == 1) {
				std::cout << 2 << ' ';
			}
			else if (a[i] == 2) {
				std::cout << 3 << ' ';
			}
			else {
				std::cout << 1 << ' ';
			}
		}
		std::cout << '\n';
		return ;
	}

	if (p[2].v + p[3].v == p[1].v) {
		int num = 0;
		rep(i, 1, n) {
			if (a[i] == p[2].id or a[i] == p[3].id) {
				std::cout << p[1].id << ' ';
			}
			else if (a[i] == p[1].id) {
				if (num <= p[2].v) {
					std::cout << p[2].id << ' ';
					num ++;
				}
				else {
					std::cout << p[3].id << '\n';
				}
			}
		}
		return ;
	}

	if (p[1].v < p[2].v + p[3].v) {
		int num1 = 0; int num2 = 0; int num3 = 0;
		rep(i, 1, n) {
			if (a[i] == p[1].id) {
				if (num2 < p[2].v) {
					std::cout << p[2].id << ' ';
					num2 ++;
				}
				else {
					std::cout << p[3].id;
					num3 ++;
				}
			}
			else if (a[i] == p[2].id) {
				if (num1 <= p[1].v) {
					std::cout << p[1].id << ' ';
					num1 ++;
				}
				else {
					std::cout << p[3].id << ' ';
					num3 ++;
				}
			}
			else if (a[i] == p[3].id) {
				if (num1 < p[1].v) {
					std::cout << p[1].id << ' ';
					num1 ++;
				}
				else {
					std::cout << p[2].id << ' ';
					num2 ++;
				}
			}
		}
	}

	if (p[1].v > p[2].v + p[3].v) {
		int num1 = 0; int num2 = 0; int num3 = 0;
		rep(i, 1, n) {
			if (a[i] == p[1].id) {
				if (num2 < p[2].v) {
					std::cout << p[2].id << ' ';
					num2 ++;
				}
				else {
					std::cout << p[3].id;
					num3 ++;
				}
			}
			else if (a[i] == p[2].id) {
				if (num1 <= p[1].v) {
					std::cout << p[1].id << ' ';
					num1 ++;
				}
				else {
					std::cout << p[3].id << ' ';
					num3 ++;
				}
			}
			else if (a[i] == p[3].id) {
				if (num1 < p[1].v) {
					std::cout << p[1].id << ' ';
					num1 ++;
				}
				else {
					std::cout << p[2].id << ' ';
					num2 ++;
				}
			}
		}
	}
    /*return AC*/
/*
Test Sample

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