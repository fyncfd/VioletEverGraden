/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-06 16:32:43
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#define  _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O2")
#include "bits/stdc++.h"
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using ldb = long double;
typedef unsigned long long u64;
typedef __int128 i128;
typedef unsigned __int128 u128;

const double eps = 1e-9;
constexpr int INF = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr i64 mod = 998244353;
constexpr i64 MOD = 1e9 + 7;
constexpr int MAXN = 0;

/*
* @Author: AlgoStruggler
* ModInt 支持动态取模 根据输入内容动态修改 MOD 的方法：Z::setMod(p) 。
* 代码借鉴 Wida 收录的 jiangly 代码模板 取模类（MLong & MInt 新版）
* 提交自：2023-08-14: https://ac.nowcoder.com/acm/contest/view-submission?submissionId=63433564
* 收录在https://www.cnblogs.com/WIDA/p/17633758.html#%E5%8F%96%E6%A8%A1%E7%B1%BBmlong--mint-%E6%96%B0%E7%89%88
* 修改：增加了不等关系比较的重载运算符和前后置自增自减的运算符，去除了32位几乎用不到的MInt。
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
class ModInt {
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
    constexpr ModInt() : x(0) {}
    constexpr ModInt(i64 x) : x{Normalize(x % getMod())} {}
    
    constexpr static void setMod(i64 _Mod) {
        Mod = _Mod;
    }

    constexpr i64 val() const { 
        return x; 
    }
    
    explicit constexpr operator i64() const { 
        return x; 
    }

    constexpr ModInt operator - () const {
        return ModInt(-x);
    }

    constexpr ModInt inv() const {
        assert(x != 0);
        return ksm(*this, getMod() - 2);
    }

    constexpr ModInt pow(u64 b) const {
        return ksm(*this, b);
    }

    constexpr ModInt &operator *= (ModInt rhs) & {
        x = ksc(x, rhs.x, getMod());
        return *this;
    }
    constexpr ModInt &operator += (ModInt rhs) & {
        x = Normalize(x + rhs.x);
        return *this;
    }
    constexpr ModInt &operator -= (ModInt rhs) & {
        x = Normalize(x - rhs.x);
        return *this;
    }
    constexpr ModInt &operator /= (ModInt rhs) & {
        return *this *= rhs.inv();
    }

    constexpr ModInt& operator ++ () {
        x = Normalize(x + 1);
        return *this;
    }
    
    constexpr ModInt operator ++ (int) {
        ModInt tmp = *this;
        ++ (*this);
        return tmp;
    }
    
    constexpr ModInt& operator -- () {
        x = Normalize(x - 1);
        return *this;
    }
    
    constexpr ModInt operator -- (int) {
        ModInt tmp = *this;
        -- (*this);
        return tmp;
    }

    friend constexpr ModInt operator * (ModInt lhs, ModInt rhs) {
        ModInt res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr ModInt operator + (ModInt lhs, ModInt rhs) {
        ModInt res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr ModInt operator - (ModInt lhs, ModInt rhs) {
        ModInt res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr ModInt operator / (ModInt lhs, ModInt rhs) {
        ModInt res = lhs;
        res /= rhs;
        return res;
    }

    friend constexpr bool operator == (ModInt lhs, ModInt rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator != (ModInt lhs, ModInt rhs) {
        return lhs.val() != rhs.val();
    }

    friend constexpr bool operator < (ModInt lhs, ModInt rhs) {
        return lhs.val() < rhs.val();
    }
    friend constexpr bool operator <= (ModInt lhs, ModInt rhs) {
        return lhs.val() <= rhs.val();
    }

    friend constexpr bool operator > (ModInt lhs, ModInt rhs) {
        return lhs.val() > rhs.val();
    }

    friend constexpr bool operator >= (ModInt lhs, ModInt rhs) {
        return lhs.val() >= rhs.val();
    }

    friend constexpr std::istream &operator >> (std::istream &is, ModInt &a) {
        i64 v;
        is >> v;
        a = ModInt(v);
        return is;
    }
    friend constexpr std::ostream &operator << (std::ostream &os, const ModInt &a) {
        return os << a.val();
    }
};
template<>
i64 ModInt<0>::Mod = 998244353;

using Z998244353 = ModInt<998244353>;
using Z1e9_7 = ModInt<1000000007>;
using Z1e9_9 = ModInt<1000000009>;

constexpr auto inv2_998 = Z998244353(2).inv();
constexpr auto inv2_1e9_7 = Z1e9_7(2).inv();
constexpr auto inv2_1e9_9 = Z1e9_9(2).inv();

using DynZ = ModInt<0>;
using Z = Z1e9_7;

static inline void VioletEverGraden() {
    i64 n;
    std::cin >> n;

    Z ans = 2;
    ans = ans.pow(n / 2);

    std::cout << ans << '\n';
    
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

2

2

5

4


*/
}

signed main() {
#ifdef Algostruggler
    freopen("A.in", "r", stdin);
#endif // Algostruggler

    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    /*std::cout << std::fixed << std::setprecision(9);
    std::cerr << std::fixed << std::setprecision(9);*/

    int _ = 1;
    //for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}