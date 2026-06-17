/*1.深呼吸，不要紧张，慢慢读题，读明白题，题目往往比你想的简单。
2.暴力枚举:枚举什么，是否可以使用一些技巧加快枚举速度（预处理、前缀和、数据结构、数论分块）
3.贪心:需要排序或使用数据结构（pq）吗，这么贪心一定最优吗。
4.二分：满足单调性吗，怎么二分，如何确定二分函数返回值是什么。
5.位运算：按位贪心，还是与位运算本身的性质有关。
6.数学题：和最大公因数、质因子、取模是否有关。
7.dp：怎么设计状态，状态转移方程是什么，初态是什么，使用循环还是记搜转移。
8.搜索：dfs 还是 bfs ，搜索的时候状态是什么，需要记忆化吗。
9.树上问题：是树形dp、树上贪心、或者是在树上搜索。
10.图论：依靠什么样的关系建图，是求环统计结果还是最短路。
11.组合数学：有几种值，每种值如何被组成，容斥关系是什么。
12.交互题：log(n)次如何二分，2*n 次如何通过 n 次求出一些值，再根据剩余次数求答案。
13.如果以上几种都不是，多半是有一个 point 你没有注意到，记住正难则反。*/
 
#define _CRT_SECURE_NO_WARNINGS
 
#pragma GCC optimize(3,"Ofast","inline")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
 
#include "iostream"
#include "vector"
#include "map"
#include "queue"
#include "set"
#include "string"
#include "stack"
#include "string.h"
#include "algorithm"
#include "cmath"
#include "numeric"
#include "functional"
#include "iomanip"
#include "unordered_set"
#include "unordered_map"
#include "type_traits"
#include "ctime"
#include "utility"
#include "chrono"
#include "assert.h"
#include "cctype"
#include "tuple"
#include "any"
#include "array"
//#include "ext/pb_ds/assoc_container.hpp"
 
using i32 = int;
using LL = long long;
using ULL = unsigned long long;
using DB = double;
using FT = float;
using LDB = long double;
//using namespace std;
//using namespace __gnu_pbds;
template <typename T> 
using PQ = std::priority_queue<T>;
template<class T> 
using MATRIX = std::vector<std::vector<T>>;
template <typename T>
using VEC = std::vector<T>;
template <class Key, class Value>
using UMP = std::unordered_map<Key, Value>;
template <typename T>
using UST = std::unordered_set<T>;
//template <typename Key, typename Value>
//using HASH = __gnu_pbds::gp_hash_table<Key, Value>;

template<class T> concept Signed = std::is_signed_v<T>;
template<class T> concept Unsigned = std::is_unsigned_v<T>;
template<class T> concept Arithmetic = std::is_arithmetic_v<T>;
 
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
typedef std::pair<DB, DB> PDD;
typedef std::pair<std::string, std::string> PSS;
typedef std::pair<std::string, LL> PSL;
typedef std::pair<LL, std::string> PLS;
typedef std::pair<std::string, DB> PSD;
typedef std::pair<DB, std::string> PDS;
typedef std::pair<LL, DB> PLD;
typedef std::pair<DB, LL> PDL;
typedef std::pair<char, LL> PCL;
typedef std::pair<LL, char> PLC;
 
typedef std::vector<PII> VPII;
typedef std::vector<PLL> VPLL;
typedef std::vector<PDD> VPDD;
typedef std::vector<PSS> VPSS;
typedef std::vector<PSL> VPSL;
typedef std::vector<PLS> VPLS;
typedef std::vector<PSD> VPSD;
typedef std::vector<PDS> VPDS;
typedef std::vector<PLD> VPLD;
typedef std::vector<PDL> VPDL;
typedef std::vector<PCL> VPCL;
typedef std::vector<PLC> VPLC;
typedef std::vector<int> VI;
typedef std::vector<VI> VVI;
typedef std::vector<bool> VB;
typedef std::vector<VB> VVB;
typedef std::vector<DB> VD;
typedef std::vector<VD> VVD;
typedef std::vector<LL> VL;
typedef std::vector<VL> VVL;
typedef std::vector<char> VC;
typedef std::vector<VC> VVC;
typedef std::vector<std::string> VS;
typedef std::vector<VS> VVS;
 
template<typename T> bool ckMax(T& a, const T& b) {
    return a < b ? a = b, true : false;
}
template<typename T> bool ckMin(T& a, const T& b) {
    return a > b ? a = b, true : false;
}
 
#define ALL(x) x.begin(),x.end()
#define RALL(x) x.rbegin(),x.rend()
#define UPB upper_bound
#define LWB lower_bound
#define REP(i, l, r) for (int i = l; i <= r; i++)
#define RED(i, l, r) for (int i = l; i >= r; i--)
#define LOP(i, x) for (auto i : x)
#define MST(x,y) memset(x ,y , sizeof(x))
#define PB push_back
#define EB emplace_back
#define yes std::cout << "yes\n"
#define no std::cout << "no\n"
#define Yes std::cout << "Yes\n"
#define No std::cout << "No\n"
#define YES std::cout << "YES\n"
#define NO std::cout << "NO\n"
#define PTF(x) std::cout<<x
#define CEL std::cout << std::endl
#define CES std::cout<<" "
#define RECIN(a,n) rep(i, 1, n){std::cin >> a[i];}
#define RECOUT(a,n) rep(i, 1, n){std::cout<<a[i]<<" ";}
#define PB push_back
#define QB pop_back
#define EB emplace_back
#define FI first
#define SE second
#define MAXE max_element
#define MINE min_element
#define MPR make_pair
#define UPB upper_bound
#define LWB lower_bound
#define CFS(x) std::cout << std::fixed << std::setprecision(x)

const DB EPS = 1e-9;
constexpr int INF = 0x3f3f3f3f;
constexpr LL LINF = 0x3f3f3f3f3f3f3f3f;
constexpr LL mod = 998244353;
constexpr LL MOD = 1e9 + 7;
int dx[] = {0, 0, 1, 0, -1};
int dy[] = {0, -1, 0, 1, 0};
 
static inline void VioletEverGarden();

auto __INIT__ = []() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout.tie(nullptr);
    return 0;
};

signed main() {
#ifdef LOCAL
    freopen("A.in", "r", stdin);
#endif // LOCAL

    __INIT__();

    int _ = 1;
    //for (std::cin >> _; _; _--)
        VioletEverGarden();

    return 0;
}

/*------------------------------SORT_AND_UNIQUE----------------------------*/
template <class T>
void REV(T *a, int n) {
    std::reverse(a + 1, a + 1 + n);
}
template <class T>
void SRT(T *a, int n) {
    std::sort(a + 1, a + 1 + n);
}
template <class T>
int UNI(T *a, int n) {
    std::sort(a + 1, a + 1 + n);
    return std::unique(a + 1, a + 1 + n) - (a + 1);
}
template <class T>
int POS(T *a, int n, T v) {
    return std::lower_bound(a + 1, a + 1 + n, v) - a;
}
template <class T>
int firstGe(T *a, int n, T v) {
    return std::lower_bound(a + 1, a + 1 + n, v) - a;
}
template <class T>
int lastLe(T *a, int n, T v) {
    return std::upper_bound(a + 1, a + 1 + n, v) - a - 1;
}

/* READ_AND_WRITE */

template <class T>
void _RD(T &x) {
    std::cin >> x;
}
void _RD(int &x) {
    scanf("%d", &x);
}
void _RD(LL &x) {
    scanf("%lld", &x);
}
void _RD(DB &x) {
    scanf("%lf", &x);
}
void _RD(char &x) {
    scanf(" %c", &x);
}
void _RD(char *x) {
    scanf("%s", x + 1);
}
template<class T, class U>
void _RD(std::pair<T, U> &x) {
    _RD(x.first);
    _RD(x.second);
}
void RD() {
}
template <class T, class... U>
void RD(T &head, U &...tail) {
    _RD(head);
    RD(tail...);
}
template <class T>
void RDN(T *a, int n) {
    for (int i = 1; i <= n; ++i)
        _RD(a[i]);
}

template <class T>
void _WT(const T &x) {
    std::cout << x;
}
void _WT(const int &x) {
    printf("%d", x);
}
void _WT(const LL &x) {
    printf("%lld", x);
}
void _WT(const DB &x) {
    printf("%.12f", x);
}
void _WT(const char &x) {
    putchar(x);
}
void _WT(const char *x) {
    printf("%s", x + 1);
}
template <class T, class U>
void _WT(const std::pair<T, U> &x) {
    _WT(x.first);
    putchar(' ');
    _WT(x.second);
}
void WT() {
}
template <class T, class... U>
void WT(const T &head, const U &...tail) {
    _WT(head);
    putchar(sizeof...(tail) ? ' ' : '\n');
    WT(tail...);
}
template <class T>
void WTN(T *a, int n) {
    for (int i = 1; i <= n; ++i) {
        _WT(a[i]);
        putchar(" \n"[i == n]);
    }
}

template <class T>
void WTV(const std::vector<T> &x, bool ln = false) {
    WT(x.size());
    for (auto i = x.begin(); i != x.end(); ++i) {
        _WT(*i);
        putchar(ln ? '\n' : ' ');
    }
    if (!ln)
        putchar('\n');
}

#ifdef LOCAL
#define D1(a)           std::cerr << #a << " = " << (a) << std::endl
#define D2(a, b)        std::cerr << #a << " = " << (a) << ", " << #b << " = " << (b) << std::endl
#define D3(a, b, c)     std::cerr << #a << " = " << (a) << ", " << #b << " = " << (b) << ", " \
                             << #c << " = " << (c) << std::endl
#define D4(a, b, c, d)  std::cerr << #a << " = " << (a) << ", " << #b << " = " << (b) << ", " \
                             << #c << " = " << (c) << ", " << #d << " = " << (d) << std::endl
#define ASSERT(x) assert(x)
#else
#define D1(a)
#define D2(a, b)
#define D3(a, b, c)
#define D4(a, b, c, d)
#define ASSERT(x)
#endif

/* CMIN_AND_CMAX */

template <typename T>
void cmin(T &x, T y) {
    if (y < x)
        x = y;
}

template <typename T>
void cmax(T &x, T y) {
    if (y > x)
        x = y;
}

#ifdef LOCAL
int rnd_seed = 19937;
#else
int rnd_seed = std::chrono::duration_cast<std::chrono::nanoseconds>(
                    std::chrono::steady_clock::now().time_since_epoch()).count();
#endif // LOCAL


/* MOD must be a prime. if not, don't use inv() */

struct ModularIntegers {
#define mint ModularIntegers
    int num;
    mint() {
        num = 0;
    }
    template <typename T>
    mint(const T& x) {
        LL tmp = x;
        if (tmp >= MOD) {
            if (tmp < (MOD << 1)) tmp -= MOD;
            else tmp %= MOD;
        } else if (tmp < 0) {
            if (tmp >= -MOD) tmp += MOD;
            else if (tmp %= MOD) tmp += MOD;
        }
        num = tmp;
    }
    friend mint operator+(const mint &x, const mint &y) {
        mint res;
        res.num = x.num + y.num;
        if (res.num >= MOD) res.num -= MOD;
        return res;
    }
    friend mint operator-(const mint &x, const mint &y) {
        mint res;
        res.num = x.num - y.num;
        if (res.num < 0) res.num += MOD;
        return res;
    }
    friend mint operator*(const mint &x, const mint &y) {
        mint res;
        res.num = 1LL * x.num * y.num % MOD;
        return res;
    }
    friend mint operator/(const mint &x, const mint &y) {
        return x * y.inv();
    }
    friend bool operator==(const mint &x, const mint &y) {
        return x.num == y.num;
    }
    friend bool operator!=(const mint &x, const mint &y) {
        return x.num != y.num;
    }
    mint operator+() {
        return +this->num;
    }
    mint operator-() {
        return -this->num;
    }
    mint& operator+=(const mint &x) {
        if ((this->num += x.num) >= MOD) this->num -= MOD;
        return *this;
    }
    mint& operator-=(const mint &x) {
        if ((this->num -= x.num) < 0) this->num += MOD;
        return *this;
    }
    mint& operator*=(const mint &x) {
        this->num = 1LL * this->num * x.num % MOD;
        return *this;
    }
    mint& operator/=(const mint &x) {
        this->num = ((*this) * x.inv()).num;
        return *this;
    }
    mint pow(LL x) const {
        mint res(1), cur(this->num);
        for (; x; cur *= cur, x >>= 1)
            if (x & 1) res *= cur;
        return res;
    }
    mint inv() const {
        return pow(MOD - 2);
    }
    operator int() {
        return num;
    }
    operator LL() {
        return num;
    }
#undef mint
};

typedef ModularIntegers mint;

void _RD(mint &x) {
    scanf("%d", &x.num);
}
void _WT(const mint &x) {
    printf("%d", x.num);
}

/*-------------------------------MY_CODE_BEGIN--------------------------------*/
//#define int long long
constexpr int MAXN = 0;
int a, b, c;
/*---------------------------------------------------------------------------*/
static inline void VioletEverGarden() {
    std::cin >> a >> b >> c;

    if (a * b - c <= 0) {
    	YES;
    	return ;
    }
    NO;

    /*return AC*/
/*
Test Sample

3 5 16

YES

2 2 2 

NO


*/
}

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

namespace dsu {
    template <typename T>
    class dsu {
        private:
            std::vector<T> fa; // 父节点数组
            std::vector<T> rk; // 秩，按秩合并
        public:
            // 默认构造函数
            dsu() = default;

            // 带参的构造函数，初始化n个元素
            explicit dsu(T n) {
                init(n);
            }
            // 初始化函数
            void init(T n) {
                fa.resize(n + 1);
                std::iota(fa.begin() + 1, fa.end(), 1); // 初始化每个元素的父节点为自己
                rk.assign(n + 1, 1); // 初始化每个元素的秩为1
            }
            // 查找根节点（路径压缩）
            T find(T x) {
                if (fa[x] != x) {
                    return find(fa[x]); // 路径压缩
                }
                return fa[x];
            }
            // 合并两个集合（按秩合并）
            void merge(T x, T y) {
                T rx = find(x);
                T ry = find(y);
                if (rx == ry) {
                    return; // 如果已经在同一个集合，直接返回
                }
                if (rk[rx] < rk[ry]) {
                    std::swap(rx, ry); // 保证rx的秩更大
                }
                fa[ry] = rx; // 将ry的父节点指向rx
                if (rk[rx] == rk[ry]) {
                    rk[rx]++; // 如果秩相等，rx的秩加1
                }
            }

            // 判断两个元素是否在同一个集合
            bool same(T x, T y) {
                return find(x) == find(y);
            }

            // 返回元素所在集合的秩
            T rank(T x) {
                return rk[find(x)];
            }
    };
}

namespace fio {
    template <typename T>
    class fio {
        public:
            inline void write(LL x, char end = '\0') {//快写，超过1e6用起来很快
                if (x < 0) {
                    putchar('-');
                    x = -x;
                }
                if (x > 9) {
                    write(x / 10);
                }
                putchar(x % 10 + '0');
                if (end != '\0') {
                    putchar(end);
                }
            }
            inline T read() {
                LL x = 0;
                short flag = 1;
                char c = getchar();
                while (c < '0' || c > '9') {//快写，超过1e6用起来很快
                    if (c == '-') {
                        flag = -1;
                    }
                    c = getchar();
                }
                while (c >= '0' && c <= '9') {
                    x = (x << 3) + (x << 1) + (c ^ 48);
                    c = getchar();
                }
                return x * flag;
            }
    };
}

template<class Info, class Tag>
struct LazySegmentTree {
    int n;
    std::vector<Info> info;
    std::vector<Tag> tag;
    LazySegmentTree() : n(0) {}
    LazySegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    LazySegmentTree(std::vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        init(std::vector(n_, v_));
    }
    template<class T>
    void init(std::vector<T> init_) {
        n = init_.size();
        info.assign(4 << std::__lg(n), Info());
        tag.assign(4 << std::__lg(n), Tag());
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init_[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    void apply(int p, const Tag &v) {
        info[p].apply(v);
        tag[p].apply(v);
    }
    void push(int p) {
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
        tag[p] = Tag();
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        push(p);
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        push(p);
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
    void rangeApply(int p, int l, int r, int x, int y, const Tag &v) {
        if (l >= y || r <= x) {
            return;
        }
        if (l >= x && r <= y) {
            apply(p, v);
            return;
        }
        int m = (l + r) / 2;
        push(p);
        rangeApply(2 * p, l, m, x, y, v);
        rangeApply(2 * p + 1, m, r, x, y, v);
        pull(p);
    }
    void rangeApply(int l, int r, const Tag &v) {
        return rangeApply(1, 0, n, l, r, v);
    }
    void half(int p, int l, int r) {
        if (info[p].act == 0) {
            return;
        }
        if ((info[p].min + 1) / 2 == (info[p].max + 1) / 2) {
            apply(p, {-(info[p].min + 1) / 2});
            return;
        }
        int m = (l + r) / 2;
        push(p);
        half(2 * p, l, m);
        half(2 * p + 1, m, r);
        pull(p);
    }
    void half() {
        half(1, 0, n);
    }
    
    template<class F>
    int findFirst(int p, int l, int r, int x, int y, F &&pred) {
        if (l >= y || r <= x) {
            return -1;
        }
        if (l >= x && r <= y && !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        push(p);
        int res = findFirst(2 * p, l, m, x, y, pred);
        if (res == -1) {
            res = findFirst(2 * p + 1, m, r, x, y, pred);
        }
        return res;
    }
    template<class F>
    int findFirst(int l, int r, F &&pred) {
        return findFirst(1, 0, n, l, r, pred);
    }
    template<class F>
    int findLast(int p, int l, int r, int x, int y, F &&pred) {
        if (l >= y || r <= x) {
            return -1;
        }
        if (l >= x && r <= y && !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        push(p);
        int res = findLast(2 * p + 1, m, r, x, y, pred);
        if (res == -1) {
            res = findLast(2 * p, l, m, x, y, pred);
        }
        return res;
    }
    template<class F>
    int findLast(int l, int r, F &&pred) {
        return findLast(1, 0, n, l, r, pred);
    }
    
    void maintainL(int p, int l, int r, int pre) {
        if (info[p].difl > 0 && info[p].maxlowl < pre) {
            return;
        }
        if (r - l == 1) {
            info[p].max = info[p].maxlowl;
            info[p].maxl = info[p].maxr = l;
            info[p].maxlowl = info[p].maxlowr = -INF;
            return;
        }
        int m = (l + r) / 2;
        push(p);
        maintainL(2 * p, l, m, pre);
        pre = std::max(pre, info[2 * p].max);
        maintainL(2 * p + 1, m, r, pre);
        pull(p);
    }
    void maintainL() {
        maintainL(1, 0, n, -1);
    }
    void maintainR(int p, int l, int r, int suf) {
        if (info[p].difr > 0 && info[p].maxlowr < suf) {
            return;
        }
        if (r - l == 1) {
            info[p].max = info[p].maxlowl;
            info[p].maxl = info[p].maxr = l;
            info[p].maxlowl = info[p].maxlowr = -INF;
            return;
        }
        int m = (l + r) / 2;
        push(p);
        maintainR(2 * p + 1, m, r, suf);
        suf = std::max(suf, info[2 * p + 1].max);
        maintainR(2 * p, l, m, suf);
        pull(p);
    }
    void maintainR() {
        maintainR(1, 0, n, -1);
    }
};

struct Tag {
    int x = 0;
    void apply(const Tag &t) & {
        x = std::max(x, t.x);
    }
};

struct Info {
    int x = 0;
    void apply(const Tag &t) & {
        x = std::max(x, t.x);
    }
};

Info operator+(const Info &a, const Info &b) {
    return {std::max(a.x, b.x)};
}

namespace gal {
    template<typename T>
    class gal {
        public:
            T gcd(T a, T b) {//欧几里得辗转相除法求最大公约数
                if (!b) {
                    return a;
                }
                return gcd(b, a % b);
            }
            T lcm(T a, T b) {//最小公倍数，其中先除后乘是尽可能避免溢出，尽量保持这个习惯
                return a / gcd(a, b) * b;
            }
    };
}

struct BigInt {
    static const int N = 1000;
    int a[N];
    BigInt(int x = 0) : a{} {
        for (int i = 0; x; i++) {
            a[i] = x % 10;
            x /= 10;
        }
    }
    BigInt &operator*=(int x) {
        for (int i = 0; i < N; i++) {
            a[i] *= x;
        }
        for (int i = 0; i < N - 1; i++) {
            a[i + 1] += a[i] / 10;
            a[i] %= 10;
        }
        return *this;
    }
    BigInt &operator/=(int x) {
        for (int i = N - 1; i >= 0; i--) {
            if (i) {
                a[i - 1] += a[i] % x * 10;
            }
            a[i] /= x;
        }
        return *this;
    }
    BigInt &operator+=(const BigInt &x) {
        for (int i = 0; i < N; i++) {
            a[i] += x.a[i];
            if (a[i] >= 10) {
                a[i + 1] += 1;
                a[i] -= 10;
            }
        }
        return *this;
    }
};

std::ostream &operator<<(std::ostream &o, const BigInt &a) {
    int t = BigInt::N - 1;
    while (a.a[t] == 0) {
        t--;
    }
    for (int i = t; i >= 0; i--) {
        o << a.a[i];
    }
    return o;
}

namespace ksm {
    template <typename T = LL>
    class ksm {
        public:
            T fastpow(T a, T b) {//迭代法求快速幂，避免溢出
                T res = 1;
                while (b > 0) {
                    if (b & 1) {
                        res *= a;
                    }
                    a *= a;
                    b >>= 1;
                }
                return res;
            }
            T powmod(T a, T b, T m) {//迭代法求取模快速幂
                a %= m;//先取模，确保a < m;
                T res = 1;
                while (b > 0) {
                    if (b & 1) {
                        res = (res * a) % m;
                    }
                    a = (a * a) % m;//平方后取模
                    b >>= 1;
                }
                return res;
            }
    };
}
void TestArea() {
    VioletEverGarden();
}
void TimeTest() {
    auto start = std::chrono::steady_clock::now();//使用 steady_clock 代替 system_clock
    TestArea();
    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count();//直接获取时间
    std::cout << "\ntime cost:" << duration << " /s";
}