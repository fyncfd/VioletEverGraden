/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-07 20:48:45
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
typedef __int128 i128;
typedef unsigned __int128 u128;

const double eps = 1e-9;
constexpr int INF = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr i64 mod = 998244353;
constexpr i64 MOD = 1e9 + 7;
constexpr int MAXN = 200010;

struct BigInt {
    std::vector<int> digits;
    
    BigInt(int x = 0) {
        if (x == 0) {
            digits.push_back(0);
        } else {
            while (x) {
                digits.push_back(x % 10);
                x /= 10;
            }
        }
    }
    
    BigInt &operator+=(const BigInt &x) {
        int carry = 0;
        int max_len = std::max(digits.size(), x.digits.size());
        digits.resize(max_len, 0);
        
        for (int i = 0; i < max_len; i++) {
            int sum = digits[i] + (i < x.digits.size() ? x.digits[i] : 0) + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
        }
        
        if (carry) {
            digits.push_back(carry);
        }
        
        return *this;
    }
    
    BigInt &operator*=(int x) {
        int carry = 0;
        for (int i = 0; i < digits.size(); i++) {
            long long prod = 1LL * digits[i] * x + carry;
            digits[i] = prod % 10;
            carry = prod / 10;
        }
        
        while (carry) {
            digits.push_back(carry % 10);
            carry /= 10;
        }
        
        return *this;
    }
    
    void add_at_pos(int pos, int value) {
        if (pos >= digits.size()) {
            digits.resize(pos + 1, 0);
        }
        
        digits[pos] += value;
        
        // 处理进位
        for (int i = pos; i < digits.size(); i++) {
            if (digits[i] >= 10) {
                if (i + 1 == digits.size()) {
                    digits.push_back(0);
                }
                digits[i + 1] += digits[i] / 10;
                digits[i] %= 10;
            } else {
                break;
            }
        }
    }
};

std::ostream &operator<<(std::ostream &o, const BigInt &a) {
    for (int i = a.digits.size() - 1; i >= 0; i--) {
        o << a.digits[i];
    }
    return o;
}

static inline void VioletEverGraden() {
    int N;
    std::cin >> N;

    std::vector<int> cnt(MAXN + 5, 0);
    int maxA = 0;
    
    for (int i = 0; i < N; i ++) {
        int a;
        std::cin >> a;
        cnt[a]++;
        maxA = std::max(maxA, a);
    }
    
    BigInt ans(0);
    int p = 0;
    std::vector<int> dig;
    for (int pos = 0; pos < maxA or p > 0; pos ++) {
        int sum = p;
        if (pos < MAXN) {
            for (int len = pos + 1; len <= maxA; len ++) {
                sum += cnt[len];
            }
        }
        
        dig.push_back(sum % 10);
        p = sum / 10;
    }
    
    ans.digits = dig;
    
    std::cout << ans << '\n';
    
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

4
3 3 3 3

444

3
30 10 20

111111111122222222223333333333

10
1 2 3 4 5 6 7 8 9 10

1234567900


*/
}

signed main() {
#ifdef Algostruggler
    freopen("A.in", "r", stdin);
#endif // Algostruggler

    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);

    int _ = 1;
    //for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}