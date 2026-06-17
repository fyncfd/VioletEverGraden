#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define red(i, l, r) for (int i = l ;i >= r; i --)
#define FOR(i, l, r, x) for (int i = l; i <= r; i += x)
#define ROF(i, l, r, x) for (int i = l; i >= r; i -= x)
const int dx[] = {-1, 0, 0, 1, -1, 1, -1, 1, -1};
const int dy[] = {-1, 1, -1, 0, 0, 1, 1, -1, -1};

void solve() {
    int n, m; std::cin >> n >> m;
    std::vector<std::vector<char>> g(n + 1, std::vector<char> (m + 1));
    ll l, r; std::cin >> l >> r;
    rep(i, 1, n) {
        rep(j, 1, n) {
            std::cin >> g[i][j];
        }
    }
    struct pii { int fi; int se; int dis; }; bool ok = false;
    bool vis[1005][1005] = { false };
    auto bfs = [&](int x, int y, int t) -> void {
        std::queue<pii> q;
        q.push({x, y, t});
        while (q.size()) {
            pii node = q.front();
            if(node.fi==n and node.se==m)
            {
                int ans=node.dis;
                ans/=r;
                if(ans%r!=0)
                {
                    ans++;
                }
                cout<<ans<<endl;
                ok = true;
            }
            q.pop();
            rep(i, 1, 8)
            {
                int nx=node.fi+dx[i],ny=node.se+dy[i],nt=node.dis+1;
                if(!vis[nx][ny] and nx>=1 and nx<=n and ny<=m and ny>=1 and g[nx][ny]!='0')
                {
                    q.push(pii{nx,ny,nt});
                    vis[nx][ny]=1;
                }
            }
        }
    };

    bfs(1, 1, 0);
    if (!ok) {
        std::cout << -1 << std::endl;
        return ;
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int _ = 1;
    for (std::cin >> _; _; _ --) 
        solve();

    return 0;
}

/*
3
5 5
2 3
10000
01000
00110
11001
11111
7 8
3 3
10101000
01010100
10000100
01000010
00100100
00011010
00000001
7 8
4 4
10101000
01010100
10000100
01000010
00100100
00011010
00000001
*/