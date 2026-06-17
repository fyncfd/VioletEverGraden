/*
* @Author: AlgoStruggler
* @Create Time: 2025-07-29 19:14:38
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
struct pii { int fi; int se; };
struct pll { ll fi; ll se; };

#define all(x) x.begin() + 1, x.end()
#define rep(i, l, r, x) for (decltype(l) i = (l); i <= (r); i += (x))
#define dep(i, l, r, x) for (decltype(l) i = (l); i >= (r); i -= (x))
#define lop(i, x) for (auto &i : x)

//using namespace std;
//using namespace __gnu_pbds;
template<class T> using matrix = std::vector<std::vector<T>>;
template <typename T> using pq = std::priority_queue<T>;
template<class T> using matrix = std::vector<std::vector<T>>;
template <class Key, class Value> using ump = std::unordered_map<Key, Value>;
template <typename T> using ust = std::unordered_set<T>;
//template <typename Key, typename Value> using hash = __gnu_pbds::gp_hash_table<Key, Value>;
template<class T> concept Signed = std::is_signed_v<T>;
template<class T> concept Unsigned = std::is_unsigned_v<T>;
template<class T> concept Arithmetic = std::is_arithmetic_v<T>;
template<class T> std::istream &operator >> (std::istream &cin, std::vector<T> &a) {
    rep(i, 1, a.size() - 1, 1) {
        std::cin >> a[i];
    }
    return cin;
}
template<class T> std::ostream &operator << (std::ostream &cout, std::vector<T> &a) {
    int n = a.size() - 1;
    if (!n) {
        return cout;
    }
    rep(i, 1, a.size() - 1, 1) {
        std::cout << a[i] << " \n"[i == a.size() - 1];
    }
    return cout;
}
template<class T> std::istream &operator >> (std::istream &cin, matrix<T> &a) {
    rep(i, 1, a.size() - 1, 1) {
        rep(j, 1, a[i].size() - 1, 1) {
            cin >> a[i][j];
        }
    }
    return cin;
}
template<class T> std::ostream &operator << (std::ostream &cout, const matrix<T> &a) {
    if (a.empty()) {
        return cout;
    }
    rep(i, 1, a.size() - 1, 1) {
        rep(j, 1, a[i].size() - 1, 1) {
            cout << a[i][j] << " \n"[j == a[i].size() - 1];
        }
    }
    return cout;
}
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
std::vector<int> d;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
namespace bit {
    template<typename T>
    class bit {
        private:
            std::vector<T> tree; // 树状数组
            std::vector<T> tree0; // 树状数组2，用来做区间修改，两个数组记录差分和（i - 1)倍差分
            int n; // 数组大小
        public:
            bit() = default;
            // 初始化n个元素
            explicit bit(int n) {
                init(n);
            }
            void init(int n) {
                this->n = n;
                tree.resize(n + 1); // 开n + 1 位方便数组下标从1开始
                tree0.resize(n + 1);
            }
            T lowbit(T x) {
                return x & -x;
            }
            void update(T x, T d) { // 更新树状数组，初始化树状数组也用
                T temp = x;
                while (x <= n) {
                    tree[x] += d;
                    x += lowbit(x);
                }
            }
            void update0(T x, T d) {
                while (x <= n) {
                    tree0[x] += d;
                    x += lowbit(x);
                }
            }
            T getsum0(T x) {
                T ans = 0;
                while (x > 0) {
                    ans += tree0[x];
                    x -= lowbit(x); 
                }
                return ans;
            }
            T getsum(T x) { // 维护前缀和
                T ans = 0;
                while (x > 0) {
                    ans += tree[x];
                    x -= lowbit(x);
                }
                return ans;
            }
            T query(T l, T r) {
            	return getsum(r) - getsum(l - 1);
            }
            // 做区间修改时候区间查询[l, r]的和
            T query0(T l, T r) {
                return r * getsum(r) - getsum0(r) - (l - 1) * getsum(l - 1) + getsum0(l - 1);
            }
    };
    /*
    e.g.
    bit::bit<int> b(10); // 初始化一个大小为10的树状数组
	b.update(1, 5); // 更新第1个元素的值为5
	b.update(2, 3); // 更新第2个元素的值为3
	int sum = b.query(1, 2); // 查询区间[1, 2]的和
    */
}
static inline void VioletEverGraden() {
    std::cin >> n;
    d.resize(n + 1);
    bit::bit<int> bit(n + 1);
    rep(i, 1, n - 1, 1) {
    	std::cin >> d[i];
    	bit.update(i, d[i]);
    }

    rep(i, 1, n - 1, 1) {
    	rep(j, i, n - 1, 1) {
    		std::cout << bit.query(i, j) << " \n"[j == n - 1];
    	}
    }
    /*太好了，这回只花998244353min就打完了！*/
/*
Test Sample

*/
}
/*-------------------------------Author_Fd------------------------------------*/
static inline void VioletEverGraden();

auto __FAST_IO__ = []() -> int {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    return 0;
}();

signed main() {
#ifdef LOCAL
    freopen("A.in", "r", stdin);
#endif // LOCAL

    /*std::cout << std::fixed << std::setprecision(9);
    std::cerr << std::fixed << std::setprecision(9);*/

    int _ = 1;
    //for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}