/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-23 11:43:44
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#pragma GCC optimize("O3,unroll-loops,Ofast,inline")
#include "bits/stdc++.h"

using i64 = int64_t;
using i128 =  __int128_t;

using u32 = uint32_t;
using u64 = uint64_t;
using u128 = __uint128_t;

using f32 = float;
using f64 = double;
using f80 = long double;

constexpr int INF = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr i64 mod = 998'244'353LL;
constexpr i64 MOD = 1e9 + 7;

/*
* @Author: AlgoStruggler
* 基于ModInt实现的组合数学Comb类，支持惰性计算（Lazy Evaluation）：只在需要时计算，增量扩展：每次只计算新增的部分
* 防止隐式转换。自动扩容：当查询超过当前范围时自动扩展。
* ModInt @Author: AlgoStruggler
* ModInt 支持动态取模 根据输入内容动态修改 MOD 的方法：Z::setMod(p) 。
* 代码借鉴 Wida 收录的 jiangly 代码模板 取模类（MLong & MInt 新版）
* 提交自：2023-08-14: https://ac.nowcoder.com/acm/contest/view-submission?submissionId=63433564
* 收录在https://www.cnblogs.com/WIDA/p/17633758.html#%E5%8F%96%E6%A8%A1%E7%B1%BBMLong--mint-%E6%96%B0%E7%89%88
* 修改：增加了不等关系比较的重载运算符和前后置自增自减的运算符。
* @Create Time: 2026-02-08 02:07:36
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
template <typename T>
constexpr T ksm(T a, u64 b) {
    T res = 1;
    while (b) {
        if (b & 1) {
            res *= a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}

constexpr i64 ksc(i64 a, i64 b, i64 p) {
#ifdef __SIZEOF_INT128__
    return (i64)((__int128)a * b % p);
#else
    i64 res = a * b - i64(1.L * a * b / p - 0.5L) * p;
    res %= p;
    if (res < 0) {
        res += p;
    }
    return res;
#endif
}

template <i64 P>
class MLong {
private:
    i64 x;
    static i64 Mod;

    constexpr static i64 getMod() {
        if constexpr (P > 0) {
            return P;
        } else {
            return Mod;
        }
    }

    constexpr i64 Normalize(i64 Val) const {
        i64 m = getMod();
        Val %= m;
        if (Val < 0) {
            Val += m;
        }
        return Val;
    }
public:
    constexpr MLong() : x(0) {}
    constexpr MLong(i64 x) : x{Normalize(x % getMod())} {}
    
    constexpr static void setMod(i64 _Mod) {
        Mod = _Mod;
    }

    constexpr i64 val() const { 
        return x; 
    }
    
    explicit constexpr operator i64() const { 
        return x; 
    }

    constexpr MLong inv() const {
        assert(x != 0);
        return ksm(*this, getMod() - 2);
    }

    constexpr MLong pow(u64 b) const {
        return ksm(*this, b);
    }

    constexpr MLong operator - () const {
        return MLong(-x);
    }

    constexpr MLong &operator *= (MLong rhs) & {
        x = ksc(x, rhs.x, getMod());
        return *this;
    }
    constexpr MLong &operator += (MLong rhs) & {
        x = Normalize(x + rhs.x);
        return *this;
    }
    constexpr MLong &operator -= (MLong rhs) & {
        x = Normalize(x - rhs.x);
        return *this;
    }
    constexpr MLong &operator /= (MLong rhs) & {
        return *this *= rhs.inv();
    }

    constexpr MLong& operator ++ () {
        x = Normalize(x + 1);
        return *this;
    }
    constexpr MLong operator ++ (int) {
        MLong tmp = *this;
        ++ (*this);
        return tmp;
    }
    
    constexpr MLong& operator -- () {
        x = Normalize(x - 1);
        return *this;
    }
    constexpr MLong operator -- (int) {
        MLong tmp = *this;
        -- (*this);
        return tmp;
    }

    friend constexpr MLong operator * (MLong lhs, MLong rhs) {
        MLong res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MLong operator + (MLong lhs, MLong rhs) {
        MLong res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MLong operator - (MLong lhs, MLong rhs) {
        MLong res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MLong operator / (MLong lhs, MLong rhs) {
        MLong res = lhs;
        res /= rhs;
        return res;
    }

    friend constexpr bool operator == (MLong lhs, MLong rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator != (MLong lhs, MLong rhs) {
        return lhs.val() != rhs.val();
    }

    friend constexpr bool operator < (MLong lhs, MLong rhs) {
        return lhs.val() < rhs.val();
    }
    friend constexpr bool operator <= (MLong lhs, MLong rhs) {
        return lhs.val() <= rhs.val();
    }

    friend constexpr bool operator > (MLong lhs, MLong rhs) {
        return lhs.val() > rhs.val();
    }
    friend constexpr bool operator >= (MLong lhs, MLong rhs) {
        return lhs.val() >= rhs.val();
    }

    friend constexpr std::istream &operator >> (std::istream &is, MLong &a) {
        i64 v;
        is >> v;
        a = MLong(v);
        return is;
    }
    friend constexpr std::ostream &operator << (std::ostream &os, const MLong &a) {
        return os << a.val();
    }
};

template<int P>
class MInt {
private:
    int x;
    static int Mod;

    constexpr static int getMod() {
        if constexpr (P > 0) {
            return P;
        } else {
            return Mod;
        }
    }

    constexpr int Normalize(i64 Val) const {
        int m = getMod();
        Val %= m;
        if (Val < 0) {
            Val += m;
        }
        return Val;
    }
public:
    constexpr MInt() : x(0) {}
    constexpr MInt(i64 x) : x{Normalize(x % getMod())} {}
    
    constexpr static void setMod(i64 _Mod) {
        Mod = _Mod;
    }

    constexpr int val() const { 
        return x; 
    }
    
    explicit constexpr operator int() const { 
        return x; 
    }

    constexpr MInt inv() const {
        assert(x != 0);
        return ksm(*this, getMod() - 2);
    }

    constexpr MInt pow(u64 b) const {
        return ksm(*this, b);
    }

    constexpr MInt operator - () const {
        return MInt(-x);
    }

    constexpr MInt &operator *= (MInt rhs) & {
        x = ksc(x, rhs.x, getMod());
        return *this;
    }
    constexpr MInt &operator += (MInt rhs) & {
        x = Normalize(x + rhs.x);
        return *this;
    }
    constexpr MInt &operator -= (MInt rhs) & {
        x = Normalize(x - rhs.x);
        return *this;
    }
    constexpr MInt &operator /= (MInt rhs) & {
        return *this *= rhs.inv();
    }

    constexpr MInt& operator ++ () {
        x = Normalize(x + 1);
        return *this;
    }
    constexpr MInt operator ++ (int) {
        MInt tmp = *this;
        ++ (*this);
        return tmp;
    }
    
    constexpr MInt& operator -- () {
        x = Normalize(x - 1);
        return *this;
    }
    constexpr MInt operator -- (int) {
        MInt tmp = *this;
        -- (*this);
        return tmp;
    }

    friend constexpr MInt operator * (MInt lhs, MInt rhs) {
        MInt res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MInt operator + (MInt lhs, MInt rhs) {
        MInt res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MInt operator - (MInt lhs, MInt rhs) {
        MInt res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MInt operator / (MInt lhs, MInt rhs) {
        MInt res = lhs;
        res /= rhs;
        return res;
    }

    friend constexpr bool operator == (MInt lhs, MInt rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator != (MInt lhs, MInt rhs) {
        return lhs.val() != rhs.val();
    }

    friend constexpr bool operator < (MInt lhs, MInt rhs) {
        return lhs.val() < rhs.val();
    }
    friend constexpr bool operator <= (MInt lhs, MInt rhs) {
        return lhs.val() <= rhs.val();
    }

    friend constexpr bool operator > (MInt lhs, MInt rhs) {
        return lhs.val() > rhs.val();
    }
    friend constexpr bool operator >= (MInt lhs, MInt rhs) {
        return lhs.val() >= rhs.val();
    }

    friend constexpr std::istream &operator >> (std::istream &is, MInt &a) {
        i64 v;
        is >> v;
        a = MInt(v);
        return is;
    }
    friend constexpr std::ostream &operator << (std::ostream &os, const MInt &a) {
        return os << a.val();
    }
};

template <>
i64 MLong<0>::Mod = i64(1E18) + 9;
template <>
int MInt<0>::Mod = 998244353;

using Z998244353 = MInt<998244353>;
using Z1e9_7 = MInt<1000000007>;
using Z1e9_9 = MInt<1000000009>;

constexpr auto inv2_998244353 = Z998244353(2).inv();
constexpr auto inv2_1e9_7 = Z1e9_7(2).inv();
constexpr auto inv2_1e9_9 = Z1e9_9(2).inv();

using DynZ = MInt<0>;
using Z = Z998244353;

template <typename T = Z>
class Comb {
private:
	int N;
	std::vector<T> _Factor;
	std::vector<T> _InvFactor;
	std::vector<T> _Inv;
public:
    Comb() : N{0}, _Factor{1}, _InvFactor{1}, _Inv{0} {}
    
    explicit Comb(int n) : Comb() {
        Init(n);
    }

    void Init(int M) {
        if (M <= N) {
        	return ;
        }
        
        _Factor.resize(M + 1);
        _InvFactor.resize(M + 1);
        _Inv.resize(M + 1);

        for (int i = N + 1; i <= M; i ++) {
            _Factor[i] = _Factor[i - 1] * i;
        }

        _InvFactor[M] = _Factor[M].inv();
        for (int i = M; i > N; i --) {
            _InvFactor[i - 1] = _InvFactor[i] * i;
            _Inv[i] = _InvFactor[i] * _Factor[i - 1]; 
        }
        
        N = M;
    }

    Z Fac(int M) {
        if (M < 0) {
        	return 0; 
        }
        if (M > N) {
        	Init(std::max(M, N * 2));
        }
        return _Factor[M];
    }

    Z InvFac(int M) {
        if (M < 0) {
        	return 0;
        }
        if (M > N) {
        	Init(std::max(M, N * 2));
        }
        return _InvFactor[M];
    }
    
    Z Inv(int M) {
        if (M == 0) {
        	return 0;
        }
        if (M > N) {
        	Init(std::max(M, N * 2));
        }
        return _Inv[M];
    }

    Z C(int N, int M) {
        if (N < M or M < 0) {
        	return 0;
        }
        return Fac(N) * InvFac(M) * InvFac(N - M);
    }

    Z A(int n, int m) {
        if (n < m or m < 0) {
        	return 0;
        }
        return Fac(n) * InvFac(n - m);
    }

    Z Stirling2(int n, int k) {
        if (n < k or k < 0) {
        	return 0;
        }
        if (n == k or k == 1) {
        	return 1;
        }
        if (k == 0) {
        	return (n == 0) ? 1 : 0;
        }
        
        Z res = 0;
        for (int i = 0; i <= k; i ++) {
            Z term = C(k, i) * Z(i).pow(n);
            if ((k - i) & 1) {
            	res -= term;
            } else {
            	res += term;
            }
        }
        return res * InvFac(k);
    }

    Z Catalan(int n) {
        if (n < 0) return 0;
        return C(2 * n, n) * Inv(n + 1);
    }
};

constexpr int MAXN = 5e5 + 25;
Comb<> comb(MAXN);

static inline void VioletEverGraden() {
    int n;
    std::cin >> n;

    std::vector<i64> a(n + 1);
    for (int i = 1; i <= n; i ++) {
    	std::cin >> a[i];
    }

/*
* @Author: AlgoStruggler
* 链式前向星建图，AddEdge函数默认构造无边权的边。
* @Create Time: 2025-02-03 13:10:02
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
* 愿幸运女神与最纯粹的前行者同在。
*/
	int tot = 1;
	struct Edge {
		int to; int nxt; int w;
	};
	std::vector<int> head(n + 1, -1);
	std::vector<Edge> G(2 * n + 10);
	auto AddEdge = [&](int u, int v, int w = 0) -> void {
		G[tot].to = v;
		G[tot].nxt = head[u];
		G[tot].w = w;
		head[u] = tot ++;
	};

	int __ = n - 1;
	while (__ --) {
		int u, v, w;
		std::cin >> u >> v;
		// std::cin >> u >> v >> w;
		AddEdge(u, v); AddEdge(v, u);
		// AddEdge(u, v, w); AddEdge(v, u, w);
	}

    bool ok = true;
    std::vector<i64> minv(n + 1, 0), maxv(n + 1, 0);
    std::vector<Z> ans(n + 1, (Z)0);
    auto dfs = [&](auto &&dfs, int u, int fa) -> void {
        std::vector<int> son;
        for (int i = head[u]; ~i; i = G[i].nxt) {
            int v = G[i].to;
            if (v == fa) {
                continue;
            }
            dfs(dfs, v, u);
            son.push_back(v);
        }

        int k = son.size();
        if (k == 0) {
            ans[u] = 1;
            minv[u] = maxv[u] = a[u];
            return ;
        }

        std::sort(son.begin(), son.end(), 
            [&](int x, int y) -> bool {
                return minv[x] < minv[y];
            });

        for (int i = 0; i < k - 1; i ++) {
            int u1 = son[i], u2 = son[i + 1];
            if (maxv[u1] > minv[u2]) {
                ok = false;
                ans[u] = 0;
                return ;
            }
        }

        if (a[u] > minv[son[0]]) {
            ok = false;
            ans[u] = 0;
            return;
        }

        std::map<std::pair<i64,i64>, int> mp;
        for (int v : son) {
            mp[{minv[v], maxv[v]}] ++;
        }

        Z prob = 1;
        for (auto &[x, y] : mp) {
            prob *= comb.Fac(y);
        }
        prob /= comb.Fac(k);

        ans[u] = prob;
        for (int v : son) {
            ans[u] *= ans[v];
        }

        minv[u] = a[u];
        maxv[u] = a[u];
        for (int v : son) {
            minv[u] = std::min(minv[u], minv[v]);
            maxv[u] = std::max(maxv[u], maxv[v]);
        }
    };

    dfs(dfs, 1, 0);

    std::cout << (ok ? ans[1] : Z(0)) << '\n';
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

2
3
1 2 3
1 2
1 3
3
2 1 3
1 2
1 3

499122177
0


*/
}

signed main() {
#ifdef Algostruggler
    freopen("A.in", "r", stdin);
#endif // Algostruggler

    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    // std::cout << std::fixed << std::setprecision(12), std::cerr << std::fixed << std::setprecision(12);

    for (int _ = [&]() -> int { int T; std::cin >> T; return T; }(); _; _ --)
        VioletEverGraden();

    return 0;
}