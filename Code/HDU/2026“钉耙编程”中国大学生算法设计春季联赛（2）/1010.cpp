/*
* @Author: AlgoStruggler
* @Create Time: 2026-03-27 20:14:04
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
constexpr i64 INF_COMB = 1e18 + 1;

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

constexpr int MAXN = 1e6 + 5;
Comb<> comb(MAXN);

i64 f(i64 r) {
    if (r >= 60) return INF_COMB;
    i64 res = 1;
    for (i64 i = 0; i < r; i++) {
        if (res > INF_COMB / 2) return INF_COMB;
        res *= 2;
    }
    return res;
}

static inline void VioletEverGraden() {
    int x;
    i64 k;
    std::cin >> x >> k;

/*    while (true) {
        i64 cnt = 0;
        for (i64 s = len; s <= x; s++) {
            i64 add = CC(s - 1, len - 1);
            if (cnt > INF_COMB - add) {
                cnt = INF_COMB;
                break;
            }
            cnt += add;
            if (cnt > INF_COMB) cnt = INF_COMB;
        }
        
        if (k > cnt) {
            k -= cnt;
            len++;
        } else {
            break;
        }
    }
    
    std::vector<i64> ans;
    i64 rem = x;
    i64 cur_len = len;
    
    while (cur_len > 0) {
        for (i64 v = 1; v <= rem - (cur_len - 1); v++) {
            if (cur_len == 1) {
                if (k == 1) {
                    ans.push_back(rem);
                    cur_len = 0;
                    break;
                }
                k--;
            } else {
                i64 cnt = CC(rem - v - 1, cur_len - 2);
                if (cnt > INF_COMB) cnt = INF_COMB;
                
                if (k > cnt) {
                    k -= cnt;
                } else {
                    ans.push_back(v);
                    rem -= v;
                    cur_len--;
                    break;
                }
            }
        }
    }*/

    std::vector<int> ans;
    i64 cur = 0;

    while (true) {
        if (ans.empty()) {
        } else {
            if (k == 1) {
                break;
            }
            k --;
        }

        for (int v = 1; v <= x - cur; v ++) {
            i64 sz = f(x - (cur + v));
            if (k > sz) {
                k -= sz;
            } else {
                ans.push_back(v);
                cur += v;
                break;
            }
        }
    }

    for (i64 i = 0; i < ans.size(); i ++) {
        std::cout << ans[i] << " \n"[i + 1 == ans.size()];
    }
}

signed main() {
#ifdef Algostruggler
    freopen("A.in", "r", stdin);
#endif

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int T;
    std::cin >> T;
    while (T--) {
        VioletEverGraden();
    }

    return 0;
}