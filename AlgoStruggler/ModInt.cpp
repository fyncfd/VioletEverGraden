#include "bits/stdc++.h"

using i64 = long long;
using i128 = __int128;
 
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;

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
using Z = Z1e9_7;

void VioletEverGraden() {
	Z a, b;
	std::cin >> a >> b;

	Z ans1 = a + b;
	Z ans2 = a - b;
	Z ans3 = a * b;
	Z ans4 = a / b;

	std::cout << ans1 << '\n';
	std::cout << ans2 << '\n';
	std::cout << ans3<< '\n';
	std::cout << ans4 << '\n';

/*
Test Sample
** 测试数据模数为1000000007 **

10 6

16
4
60
666666673

-5 3

1000000005
999999999
999999992
333333334


*/
}

signed main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

	int _ = 1;
    // for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}