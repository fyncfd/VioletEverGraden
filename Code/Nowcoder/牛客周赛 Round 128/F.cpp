/*
* @Author: AlgoStruggler
* @Create Time: 2026-01-25 20:01:38
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#define  _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O2")
#include "bits/stdc++.h"
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;

using i64 = long long;
using ldb = long double;
typedef unsigned long long u64;
typedef __int128 i128;
struct pii { int fi; int se; };
struct pll { i64 fi; i64 se; };
#define debug(x) std::cerr << #x << " = " << x << '\n'
#define debug2(x, y) std::cerr << #x << " = " << x << ", " << #y << " = " << y << '\n'
/*------------------------------SORT_AND_UNIQUE-------------------------------*/
const double eps = 1e-9;
constexpr int INF = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr i64 mod = 998244353;
constexpr i64 MOD = 1e9 + 7;
constexpr int MAXN = 0;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::string s;
    std::cin >> s;
    int n = (int)s.size();

    std::vector<int> fa0(n, INF); std::vector<int> fa2(n, INF);

    int cnt0 = INF; int cnt2 = INF;
    for (int i = n - 1; i >= 0; i --) {
        fa0[i] = cnt0; fa2[i] = cnt2;
        if (s[i] == '0') {
        	cnt0 = i;
        }
        if (s[i] == '2') {
        	cnt2 = i;
        }
    }

    std::vector<int> num1;
    for (int i = 0; i < n; i ++) {
        if (s[i] == '1') {
            num1.push_back(i);
        }
    }

    std::vector<bool> ok1(n, false); std::vector<bool> ok2(n, false);
    int l = 0; int r = (int)num1.size() - 1;
    while (l < r) {
        int u = num1[l]; int v = num1[r];
        bool ok = (fa0[u] < fa2[u]);
        if (!ok) {
            l ++;
            continue;
        }
        if (v > fa0[u]) {
            ok1[u] = true;
            ok2[v] = true;
            l ++; r --;
        } else {
            l ++;
        }
    }

    std::string ans;
    ans.reserve(n);
    for (int i = 0; i < n; i ++) {
        if (ok1[i]) {
            continue;
        }
        if (ok2[i]) {
            ans += '2';
        } else {
            ans += s[i];
        }
    }

    std::cout << ans << '\n';
    
    /*太好了，这回只花998244353min就打完了!
    真好。记得多手造几组。ACM拍什么拍。 */
/*
Test Sample

12101

1202

12112

12112


*/
}
/*-----------------------------Algostruggler----------------------------------*/
signed main() {
#ifdef LOCAL
    freopen("A.in", "r", stdin);
#endif // LOCAL

    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    /*std::cout << std::fixed << std::setprecision(9);
    std::cerr << std::fixed << std::setprecision(9);*/

    int _ = 1;
    //for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}