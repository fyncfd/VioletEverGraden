#include <bits/stdc++.h>

using ll = long long;

#define rep(i, l, r, x) for (int i = l; i <= r; i += x)
#define dep(i, l, r, x) for (int i = l; i >= r; i -= x)

int dx[] = {-111, 1, 1, -1, -1, 1, -1, 0, 0};
int dy[] = {-111, 1, -1, 1, -1, 0, 0, 1, -1};

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<char>> g(n + 1, std::vector<char> (m + 1));
    rep(i, 1, n, 1) {
        rep(j, 1, m, 1) {
            std::cin >> g[i][j];
        }
    }
    
    struct pii {
        int fi; int se;
        bool operator < (const pii &a) const {
            if (fi == a.fi) {
                return a.se > se;
            } else {
                return a.fi < fi;
            }
        }
    };
    std::set<pii> st;
    std::vector<pii> ans;
    ans.push_back({0, 0});
    bool vis[1005][1005] = { false };
    rep(i, 1, n, 1) {
        rep(j, 1, m, 1) {
            if (g[i][j] == 'c') {
                rep(k, 1, 8, 1) {
                    int nx = i + dx[k]; int ny = j + dy[k];
                    //std::cout << nx << ' ' << ny << "||||||???\n";
                    
                    if (nx >= 1 and nx <= n and ny >= 1 and ny <= m) {
                        if (g[nx][ny] == '.') {
                            vis[nx][ny] = true;
                        }
                    }
                }
            }

            if (g[i][j] == 'w') {
                //std::cout << "pikade zuobiao ==" << i << ' ' << j << "______\n";
                bool ok = false;
                rep(k, 1, 8, 1) {
                    int nx = i + dx[k]; int ny = j + dy[k];

                    if (nx >= 1 and nx <= n and ny >= 1 and ny <= m) {
                        if (g[nx][ny] == 'm') {
                            //std::cout << "nuanlide zuobiao ==" << nx << ' ' << ny << "?????\n";
                            ok = true;
                        }
                    }
                }

                if (!ok) {
                    rep(k, 1, 8, 1) {
                        int nx = i + dx[k]; int ny = j + dy[k];

                        if (nx >= 1 and nx <= n and ny >= 1 and ny <= m) {
                            if (g[nx][ny] == '.') {
                                if (!vis[nx][ny]) {
                                    st.insert({nx, ny});
                                }
                            }
                        }
                    }
                }
            }

            // if (!ok) {
            //     rep(k, 1, 8, 1) {
            //         int nx = i + dx[k]; int ny = j + dy[k];

            //         if (nx >= 1 and nx <= n and ny >= 1 and ny <= m) {
            //             if (g[nx][ny] == '.') {
            //                 st.insert({nx, ny});
            //             }
            //         }
            //     }
            // }
        }
    }

    for (auto p : st) {
        ans.push_back(p);
    }
    std::sort(ans.begin() + 1, ans.end(), [&](pii a, pii b) {
        if (a.fi == b.fi) {
            return a.se < b.se;
        } 
        return a.fi < b.fi;
    });

    int cnt = 0;
    rep(i, 1, ans.size() - 1, 1) {
        if (!vis[ans[i].fi][ans[i].se]) {
            cnt ++;
        }
    }

    if (cnt < 1) {
        std::cout << "Too cold!\n";
    } else {
        rep(i, 1, ans.size() - 1, 1) {
            if (!vis[ans[i].fi][ans[i].se]) {
                std::cout << ans[i].fi << ' ' << ans[i].se << '\n';
            }
        } 
    }

    // if (vis[4][5]) {
    //     std::cout << "woshidashabi\n";
    // }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int _ = 1;
    //for (std::cin >> _; _; _ --) 
        solve();

    return  0;
}

/*
6 8
wm....mw
.w..ww..
..wm.wwm
w.w....w
.m.c.m..
w.....w.

*/