/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-05 16:31:27
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
* ModInt 支持动态取模 根据输入内容动态修改 MOD 的方法：Z::setMod(p) 。
* 代码借鉴 Wida 收录的 jiangly 代码模板 取模类（MLong & MInt 新版）
* 提交自：2023-08-14: https://ac.nowcoder.com/acm/contest/view-submission?submissionId=63433564
* 收录在https://www.cnblogs.com/WIDA/p/17633758.html#%E5%8F%96%E6%A8%A1%E7%B1%BBMLong--mint-%E6%96%B0%E7%89%88
* 修改：增加了不等关系比较的重载运算符和前后置自增自减的运算符。
* @Create Time: 2026-01-27 18:56:25
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
* 愿幸运女神与最纯粹的前行者同在。
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

/*
* DSU封装类，启发式合并，根据集合大小去合并，带路径压缩。
* @Author: AlgoStruggler
* @Create Time: 2026-02-04 15:53:13
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
* 愿幸运女神与最纯粹的前行者同在。
*/
template <typename T>
class DisjointSetUnion {
private:
	int N;
	std::vector<int> Parent;
	std::vector<int> Size;
public:
    DisjointSetUnion(int n) : N(n), Parent(N + 1), Size(N + 1) {
        std::iota(Parent.begin() + 1, Parent.end(), 1);
        Size.assign(N + 1, 1);
    }

    int find(int x) {
    	while (x != Parent[x]) {
    		x = Parent[x] = Parent[Parent[x]];
    	}
    	return x;
    }

    bool same(int x, int y) {
    	return find(x) == find(y);
    }

    bool Merge(int x, int y) {
        int RootX = find(x);
        int RootY = find(y);
        
        if (RootX == RootY) {
            return false;
        }

        if (Size[RootX] < Size[RootY]) {
            std::swap(RootX, RootY);
        }
        
        Parent[RootY] = RootX;
        Size[RootX] += Size[RootY];
        
        return true;
    }

    int size(int x) {
        return Size[find(x)];
    }
};

static inline void VioletEverGraden() {
    int n;
    std::cin >> n;

    std::vector<int> a(n + 1);
    std::vector<int> deg(n + 1, 0);
    for (int i = 1; i <= n; i ++) {
        std::cin >> a[i];
        deg[a[i]] ++;
    }

    std::vector<int> sz(n + 1, 1);
    std::queue<int> q;
    for (int i = 1; i <= n; i ++) {
        if (deg[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        int v = a[u];
        sz[v] += sz[u];
        if (-- deg[v] == 0) {
            q.push(v);
        }
    }

    std::vector<bool> vis(n + 1, false);
    Z ans = 1;

    for (int i = 1; i <= n; i ++) {
        if (deg[i] > 0 && !vis[i]) {
            std::vector<int> cyc;
            int cur = i;
            while (!vis[cur]) {
                vis[cur] = true;
                cyc.push_back(cur);
                cur = a[cur];
            }
            int L = (int)cyc.size();
            int tot = 0;
            for (int u : cyc) {
                tot += sz[u];
            }

            Z f1 = Z(25).pow(tot - L);
            Z f2 = Z(25).pow(L);
            if (L % 2 == 0) {
                f2 += 25;
            } else {
                f2 -= 25;
            }
            f1 *= f2;

            ans *= f1;
        }
    }

    std::cout << ans << '\n';
/* 
愿幸运女神与最纯粹的前行者同在。 
Test Sample

2
2 1

650


*/
}

signed main() {
#ifdef Algostruggler
    freopen("A.in", "r", stdin);
#endif // Algostruggler

    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    // std::cout << std::fixed << std::setprecision(12), std::cerr << std::fixed << std::setprecision(12);

    // for (int _ = [&]() -> int { int T; std::cin >> T; return T; }(); _; _ --)
        VioletEverGraden();

    return 0;
}