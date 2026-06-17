/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-12 00:03:55
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
constexpr int MAXN = 0;

int N;
std::vector<std::pair<int, int>> G;
std::map<int, i64> mem;
std::pair<i64, std::vector<int>> qqq;

std::vector<int> query(i64 k) {
    if (qqq.first == k and k != -1) {
        return qqq.second;
    }
    
    std::cout << "? " << k << std::endl;
    int len;
    std::cin >> len;
    
    if (len == -1) {
        exit(0);
    }
    
    std::vector<int> path;
    if (len > 0) {
        path.resize(len);
        for(int i = 0; i < len; i ++) {
            std::cin >> path[i];
        }
    }

    qqq = {k, path};
    return path;
}

bool check(const std::vector<int>& prefix, const std::vector<int>& path) {
    if (path.size() < prefix.size()) return false;
    for(size_t i = 0; i < prefix.size(); i ++) {
        if (path[i] != prefix[i]) return false;
    }
    return true;
}

i64 dfs(int u, i64 uid) {
    i64 num = 1;
    std::vector<int> prefix = query(uid);
    i64 cur = uid + 1;
    
    while (true) {
        std::vector<int> path = query(cur);

        if (path.empty() or !check(prefix, path)) {
            break;
        }
        int v = path[prefix.size()];
        G.push_back({u, v});
        
        i64 cnt;
        if (mem.count(v)) {
            cnt = mem[v];
        } else {
            cnt = dfs(v, cur);
        }

        num += cnt;
        cur += cnt;
    }

    mem[u] = num;
    return num;
}

static inline void VioletEverGraden() {
    std::cin >> N;

    G.clear();
    mem.clear();
    qqq = {-1, {}};
    
   	i64 id = 1;
    
    for (int i = 1; i <= N; i ++) {
        if (mem.count(i)) {
            id += mem[i];
        } else {
           	i64 count = dfs(i, id);
            id += count;
        }
    }

    std::cout << "! " << G.size() << std::endl;
    for (const auto &edge : G) {
        std::cout << edge.first << ' ' << edge.second << std::endl;
    }
    
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

3
5

1 1

2 1 2

3 1 2 4

3 1 2 5

2 1 3

3 1 3 4

3 1 3 5

1 2

1 3

1 4

1 5

1

0

2

1 1

1 2

2 2 1

? 2
? 3
? 4
? 5
? 6
! 0
? 2
? 3
? 4
! 0
? 2
? 3
? 4
? 4
! 2
1 4
1 0


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