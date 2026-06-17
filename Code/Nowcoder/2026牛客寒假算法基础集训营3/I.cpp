/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-07 16:25:45
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
* 支持插入元素、查询最大/最小值、判断是否能表示某数、查询第k小值（支持重复值处理）、重建简化基。
* 记录插入元素的原始ID，可获取构成某个线性表示的原始元素下标。
* @Create Time: 2026-02-08 16:09:05
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
template <typename T>
class LinearBasis {
private:
    static constexpr int BASE = sizeof(T) * 8;
    std::vector<T> Basis;
    std::vector<T> Reduced_Basis;
    std::vector<u64> Basis_Mask;
    std::vector<int> Index;

    int Reduce_Size;
    bool Has_Zoro;
public:
    LinearBasis() {
        Basis.assign(BASE, T{0});
        Reduced_Basis.assign(BASE, T{0});
        Basis_Mask.assign(BASE, 0);
        Reduce_Size = 0;
        Has_Zoro = false;
    }

    bool Insert(T Val, int Id) {
        u64 Cur = 0;
        for (int i = BASE - 1; i >= 0; i --) {
            if ((Val >> i) & 1) {
                if (!Basis[i]) {
                    Basis[i] = Val;
                    Basis_Mask[i] = Cur | (1ULL << Index.size());
                    Index.push_back(Id);
                    return true;
                }

                Val ^= Basis[i];
                Cur ^= Basis_Mask[i];
            }
        }
        Has_Zoro = true;
        return false;
    }

    void ReBuild() {
        for (int i = BASE - 1; i >= 0; i --) {
            if (Basis[i]) {
                for (int j = i - 1; j >= 0; j --) {
                    if ((Basis[i] >> j) & 1) {
                        Basis[i] ^= Basis[j];
                        Basis_Mask[i] ^= Basis_Mask[j];
                    }
                }
            }
        }

        Reduce_Size = 0;
        for (int i = 0; i < BASE; i ++) {
            if (Basis[i]) {
                Reduced_Basis[Reduce_Size ++] = Basis[i];
            }
        }
    }

    T Kth_Value(i64 K) {
        if (Has_Zoro) {
            K --;
        }
        if (K == 0) {
            return T{0};
        }
        if (K >= (1ULL << Reduce_Size)) {
            return T{-1};
        }

        T res = 0;
        for (int i = 0; i < Reduce_Size; i ++) {
            if ((K >> i) & 1) {
                res ^= Reduced_Basis[i];
            }
        }

        return res;
    }

    T Max_Value() const {
        T res = 0;
        for (int i = BASE - 1; i >= 0; i --) {
            if ((res ^ Basis[i]) > res) {
                res ^= Basis[i];
            }
        }

        return res;
    }

    T Min_Value() const {
        if (Has_Zoro) {
            return T{0};
        }

        for (int i = 0; i < BASE; i ++) {
            if (Basis[i]) {
                return Basis[i];
            }
        }

        return T{0};
    }

    std::pair<bool, u64> Represent(T Val) const {
        u64 res = 0;
        for (int i = BASE - 1; i >= 0; i --) {
            if ((Val >> i) & 1) {
                if (!Basis[i]) {
                    return {false, 0ULL};
                }
                Val ^= Basis[i];
                res ^= Basis_Mask[i];
            }
        }

        return {true, res};
    }

    std::vector<int> getId(u64 S) const {
        std::vector<int> res;
        for (int i = 0; i < (int)Index.size(); i ++) {
            if (S & (1ULL << i)) {
                res.push_back(Index[i]);
            }
        }

        return res;
    }

    int Rank() const {
        int RK = 0;
        for (int i = 0; i < BASE; i ++) {
            if (Basis[i]) {
                RK ++;
            }
        }

        return RK;
    }

    bool Zero() const {
        return Has_Zoro;
    }
};

static inline void VioletEverGraden() {
    int n;
    std::cin >> n;

    std::vector<i64> a(n + 1);
    for (int i = 1; i <= n; i ++) {
    	std::cin >> a[i];
    }

    std::vector<i64> b(n + 1);
    for (int i = 1; i <= n; i ++) {
    	std::cin >> b[i];
    }

    std::vector<i64> x(n + 1);
    for (int i = 1; i <= n; i ++) {
        x[i] = a[i] ^ b[i];
    }

    LinearBasis<i64> LB;
    for (int i = 1; i <= n; i ++) {
        if (x[i] != 0) {
            LB.Insert(x[i], i);
        }
    }

    i64 sum = 0;
    for (int i = 1; i <= n; i ++) {
        sum ^= a[i];
    }

    auto [ok, mask] = LB.Represent(sum);
    if (!ok) {
        std::cout << -1 << '\n';
        return ;
    }

    std::vector<int> vis(n + 1);
    for (auto v : LB.getId(mask)) {
        vis[v] = 1;
    }

    for (int i = 1; i <= n; i ++) {
        if (vis[i]) {
            std::cout << b[i] << " \n"[i == n];
        } else {
            std::cout << a[i] << " \n"[i == n];
        }
    }
    
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

2
3
1 3 6
5 8 2
2
1 2
3 4

5 3 6
-1


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
    for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}