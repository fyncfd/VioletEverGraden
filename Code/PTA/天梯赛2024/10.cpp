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
int n;
std::string name;
std::string s;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> n;

    std::map<std::string, int> hash;
    while (n --) {
    	std::cin >> name;
    	std::cin.get();
    	getline(std::cin, s);

    	int len = s.size() - 7;

    	rep(i, 0, len) {
    		if ((s[i] == 'c' or s[i] == 'C') and
    		(s[i + 1] == 'H' or s[i + 1] == 'h') and
    		(s[i + 2] == 'A' or s[i + 2] == 'a') and
    		(s[i + 3] == 'T' or s[i + 3] == 't') and
    		(s[i + 4] == 'G' or s[i + 4] == 'g') and
    		(s[i + 5] == 'P' or s[i + 5] == 'p') and
    		(s[i + 6] == 'T' or s[i + 6] == 't')) {
    			hash[name] ++;
    		}
    	}
    }

    std::vector<std::pair<std::string, int>> ans;
    lop(x, hash) {
    	ans.push_back(x);
    }

    sort(ans.begin(), ans.end(), [&](std::pair<std::string, int> a, std::pair<std::string, int> b) {
    	if (a.second == b.second) {
    		return a.first < b.first;
    	}
    	return a.second > b.second;
    });

    if (ans.size() >= 3) {
    	rep(i, 0, 2) {
    		std::cout << ans[i].first << ' ' << ans[i].second << '\n';
    	}
    }
    else {
    	rep(i, 0, ans.size() - 1) {
    		if (ans[i].second != 0) {
    			std::cout << ans[i].first << ' ' << ans[i].second << '\n';
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