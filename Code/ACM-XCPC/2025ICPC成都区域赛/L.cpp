#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//const int N = 500005;

#define rep(i, l, r, x) for (int i = l; i <= r; i += x)

// int deep[N],siz[N],son[N], top[N], fa[N];
// void dfs1(int x, int father) {
//     deep[x] = deep[father] + 1;
//     fa[x] = father;
//     siz[x] = 1;
//     for (int i = head[x]; ~i; i = edge[i].next) {
//         int y = edge[i].to;
//         if(y != father) {
//             fa[y] = x;
//             dfs1(y, x);
//             siz[x] += siz[y];
//             if (!son[x] or siz[son[x]] < siz[y]) {
//                 son[x] = y;
//             }
//         }
//     }
// }

// void dfs2(int x, int topx) {
//     top[x] = topx;
//     if (!son[x]) return ;
//     dfs2(son[x], topx);
//     for (int i = head[x]; ~i; i = edge[i].next) {
//         int y = edge[i].to;
//         if (y != fa[x] and y != son[x])
//             dfs2(y, y);
//     }
// }

// int LCA(int x, int y) {
//     while(top[x] != top[y]) {
//         if (deep[top[x]] < deep[top[y]]) {
//             x = fa[top[x]];
//         }
//     }
//     return deep[x] < deep[y] ? x : y;
// }





// int LCA(int x, int y) {
//     while(top[x] != top[y]) {
//         if (deep[top[x]] < deep[top[y]]) {
//             x = fa[top[x]];
//         }
//     }
//     return deep[x] < deep[y] ? x : y;
// }

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n + 1); std::vector<int> b(n + 1);
    rep(i, 1, n, 1) {
        std::cin >> a[i];
        a[i] --;
    }
    rep(i, 1, n, 1) {
        std::cin >> b[i];
        b[i] --;
    }

    // std::vector<int> head(n + 1, -1);
    // struct Edge {
    //     int to; int nxt;
    // };
    // std::vector<Edege> g(n + 1);
    // int ttt = 1;
    // auto AddEdge = [&](int u, int v) -> void {
    //     g[ttt].to = v;
    //     g[ttt].nxt = head[u];
    //     head[u] = ttt ++;
    // };
    std::vector<std::vector<int>> g(n + 1);
    auto AddEdge = [&](int u, int v) -> void {
        g[u].push_back(v);
        g[v].push_back(u);
    };

    int __ = n;
    while (__ --) {
        int u, v;
        std::cin >> u >> v;
        AddEdge(u, v);
    }

    std::vector<int> fa(n + 1, -1); std::vector<int> siz(n + 1);
    auto dfs1 = [&](auto &&self, int x) -> void {
        if (fa[x] != -1) {
            g[x].erase(ranges::find(g[x], fa[x]));
        }
        siz[x] = 1;
        for (auto &y : g[x]) {
            fa[y] = x;
            self(self, y);
            siz[x] += siz[y];
            if (siz[y] > siz[g[x][0]]) {
                std::swap(y, g[x][0]);
            }
        }
    };
    dfs1(dfs1, 1);

    std::string res(n + 1, '0');
    int cnta{}; int cntb{}; int cnt0a{}; int cnt0b{};
    std::vector<int> cnt(n);
    auto modify = [&](int x, int dt) {
        auto update = [&](int num, int dt) {
            cnta -= std::max(0, cnt[num]);
            cntb -= std::max(0, -cnt[num]);
            cnt[num] += dt;
            cnta += std::max(0, cnt[num]);
            cntb += std::max(0, -cnt[num]);
        };

        if (a[x] == -1) {
            cnt0a += dt;
        } else {
            update(a[x], dt);
        }
        if (b[x] == -1) {
            cnt0b += dt;
        } else {
            update(b[x], -dt);
        }
    };
    // auto modify - [&](int x, int dt) {
    //     auto update = [&](int num, int dt) {
    //         cnta -= std::max(0, cnt[num]);
    //         cntb -= std::max(0, -cnt[num]);
    //         cnt[num] += dt;
    //         cnta += std::max(0, cnt[num]);
    //         cntb += std::max(0, -cnt[num]);
    //     };

    //     if (a[x] == -1) {
    //         cnt0a += dt;
    //     } else {
    //         update(a[x], dt);
    //     }
    //     if (b[x] == -1) {
    //         cnt0b += dt;
    //     } else {
    //         update(b[x], -dt);
    //     }
    // };


    auto dfs2 = [&](auto &&self, int x, bool ok) -> void {
        for (auto y : g[x]) {
            if (y != g[x].front()) {
                self(self, y, false);
            }
            if (g[x].size()) {
                self(self, g[x].front(), true);
            }
            modify(x, 1);
        }
        for (auto y : g[x]) {
            if (y != g[x].front()) {
                auto dfs3 = [&](auto &&self, int x) -> void {
                    modify(x, 1);
                    for (auto y : g[x]) {
                        self(self, y);
                    }
                };
                dfs3(dfs3, y);
            }
        }
        if (cnt0a >= cntb and cnt0b >= cnta) {
            res[x] = '1';
        } else {
            res[x] = '0';
        }
        if (!ok) {
            auto dfs4 = [&](auto &&self, int x) -> void {
                modify(x, -1);
                for (auto y : g[x]) {
                    self(self, y);
                }
            };
            dfs4(dfs4, x);
        }
    };
    dfs2(dfs2, 1, true);

    rep(i, 1, n - 1, 1) {
        std::cout << res[i];
    }
    std::cout << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int _ = 1;
    std::cin >> _;
    while (_ --) {
        solve();
    }

    return 0;
}


/* 

3
6
1 5 0 3 4 0
0 3 4 5 2 0
1 2
2 3
2 4
1 5
5 6
5
2 2 3 0 4
4 1 4 2 0
1 2
2 3
3 4
4 5
3
1 2 3
3 2 1
1 2
2 3

*/