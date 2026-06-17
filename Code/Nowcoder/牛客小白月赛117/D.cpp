/*
* @Author: AlgoStruggler
* @Create Time: 2025-07-25 23:46:05
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
//typedef std::pair<int, int> pii;
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
constexpr int MAXN = 1e6 + 6;
int n;
std::vector<int> a;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> n;

    std::map<int, int> sum;
    a.resize(n + 1);
    rep(i, 1, n, 1) {
    	std::cin >> a[i];
    	sum[a[i]] ++;
    }

/*    struct pii {
    	int fi; int se;
    	bool operator < (const pii &a) const {
    		if (a.se == se) {
    			return a.fi > fi;
    		} else {
    			return a.se > se;
    		}
    	}
    };
    std::set<pii> hash;
    lop(x, sum) {
    	auto [p, q] = x;
    	hash.insert({p, q});
    }

    // std::vector<int> ans; ans.push_back(-1);
    std::set<int> ans;
    rep(i, 1, n, 1) {
    	hash.erase({a[i], sum[a[i]]});
    	sum[a[i] + 1] ++;
    	hash.insert({a[i] + 1, sum[a[i] + 1]});

    	rep(j, 1, n, 1) {
    		if (i != j) {
    			hash.insert({a[j], sum[a[j]]});
    			sum[a[j] - 1] ++;
    			hash.insert({a[j] - 1, sum[a[j] - 1]});

    			// ans.push_back((*hash.rbegin()).fi);
                ans.insert((*hash.rbegin()).fi);

    			hash.erase({a[j] - 1, sum[a[j] - 1]});
    			sum[a[j] - 1] --;
    			hash.insert(a[j], sum[a[j]]);
    		}
    	}

    	hash.erase({a[i] + 1, sum[a[i] + 1]});
    	sum[a[i] + 1] --;
    	hash.insert({a[i], sum[a[i]]});
    }*/

/*    std::sort(ans.begin() + 1, ans.end(), [&](int a, int b) -> bool {
        return a < b;
    });

    rep(i, 1, ans.size() - 1, 1) {
        std::cout << ans[i] << " \n"[i == ans.size() - 1];
    }*/

    struct pii {
        int fi; int se;
        bool operator < (const pii &a) const {
            if (a.se == se) {
                return fi > a.fi;
            } else {
                return se > a.se;
            }
        }
    };
    std::set<pii> hash;
    lop(x, sum) {
        auto [p, q] = x;
        hash.insert({p, q});
    }

    bool ans[MAXN] = { false };
    rep(i, 1, n, 1) {
        if (sum[a[i]] > 0) {
            hash.erase({a[i], sum[a[i]]});
            sum[a[i] + 1] ++;
            hash.insert({a[i] + 1, sum[a[i] + 1]});
        }

        rep(j, 1, n, 1) {
            if (i != j) {
                if (sum[a[j]] > 0) {
                    hash.erase({a[j], sum[a[j]]});
                    sum[a[j - 1]] ++;
                    hash.insert({a[j] - 1, sum[a[j] - 1]});

                    ans[(*hash.begin()).fi] = true;

                    hash.erase({a[j - 1], sum[a[j - 1]]});
                    sum[a[j] - 1] --;
                    hash.insert({a[j], sum[a[j]]});
                }
            }
        }

        hash.erase({a[i] + 1, sum[a[i] + 1]});
        sum[a[i] + 1] --;
        hash.insert({a[i], sum[a[i]]});
    }

    rep(i, 0, 1000001, 1) {
        if (ans[i]) {
            std::cout << i << ' ';
        }
    }
    std::cout << std::endl;

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

    /*cout << std::fixed << std::setprecision(9);
    cerr << std::fixed << std::setprecision(9);*/


    __INIT__();

    int _ = 1;

    //for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}