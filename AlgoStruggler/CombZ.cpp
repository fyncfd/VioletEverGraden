#include "bits/stdc++.h"

using i64 = long long;
using i128 = __int128;
 
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;

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
using Z = Z1e9_7;

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

void VioletEverGraden() {
	int n, m;
	std::cin >> n >> m;

	Z ans = comb.C(m, n);

	std::cout << ans << '\n';

/*
Test Sample
测试题目来源牛客Track:https://www.nowcoder.com/practice/53f82db091b2452bae5fef4437ffd0bb?tpId=386&tqId=11262469&channelPut=tracker1
2
2 4
3 5

6
10


*/
}

signed main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

	int _ = 1;
    for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}