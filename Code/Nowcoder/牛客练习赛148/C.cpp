/*
* @Author: AlgoStruggler
* @Create Time: 2026-01-23 19:16:36
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
constexpr int MAXN = 2e5 + 10;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    int n;
    std::cin >> n;

    std::vector<int> p(n + 1);
    std::vector<int> pos(n + 1);
    for (int i = 1; i <= n; i ++) {
    	std::cin >> p[i];
    	pos[p[i]] = i;
    }

    std::vector<int> id(n + 1);
    for (int i = 1; i <= n; i ++) {
    	std::cin >> id[i];
    }

    std::vector<int> d(n + 1);
    for (int i = 1; i <= n; i ++) {
    	std::cin >> d[i];
    }

/*    std::vector<int> pos(n + 1);
    for (int i = 1; i <= n; i ++) {
    	pos[i] = i;
    }*/

/*    std::vector<int> nxt(n + 1);
    for (int i = 1; i <= n; i ++) {
    	int x = pos[i];
    	nxt[i] = d[x];
    }*/

    int cnt = 0;
    bool vis[MAXN] = {false};
    std::vector<int> cid(n + 1, 0); std::vector<int> csz;

    for (int i = 1; i <= n; i ++) {
        if (!vis[i]) {
            cnt ++;
            int cur = i; int len = 0;
            while (!vis[cur]) {
                vis[cur] = true;
                cid[cur] = cnt;
                len ++;
                int g = d[cur];
                cur = pos[g];
            }
            csz.push_back(len);
        }
    }

    bool ok[cnt + 100] = {false};
    i64 ans = 0;
    for (int i = 1; i <= n; i ++) {
        int idx = id[i];
        int c = cid[idx];
        if (!ok[c]) {
            ok[c] = true;
            ans += csz[c - 1];
        }

        std::cout << ans << " \n"[i == n];
    }

/*    for (int i = 1; i <= n; i ++) {
        if (vis[i]) continue;
        std::vector<int> tmp;
        int cur = i;
        while (!vis[cur]) {
            vis[cur] = true;
            tmp.push_back(cur);
            cur = nxt[cur];
        }

        std::vector<int> f;
        for (int val : tmp) {
            int x = pos[val];
            f.push_back(x);
            cid[x] = cnt;
        }
        c.push_back(f);
        csz.push_back((int)f.size());
        cnt ++;
    }

    int ans = 0;
    bool bk[MAXN] = {false}; bool cbk[MAXN] = {false};
    for (int i = 1; i <= n; i ++) {
        int pos = id[i];
        if (!bk[pos]) {
            bk[pos] = true;
            int rid = cid[pos];
            if (!cbk[rid]) {
                cbk[rid] = true;
                ans += csz[rid];
            }
        }*/
    
    /*太好了，这回只花998244353min就打完了!
    真好。记得多手造几组。ACM拍什么拍。 */
/*
Test Sample

4
1 2 3 4
1 2 3 4
2 1 3 4

2 2 3 4

5
1 2 3 4 5
4 4 4 1 2
2 1 4 5 3

3 3 3 5 5


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