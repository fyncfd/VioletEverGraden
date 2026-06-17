#include <bits/stdc++.h>

using ll = long long;

#define rep(i, l, r) for (int i = l; i <= r; i ++) 
#define red(i, l, r) for (int i = l; i >= r; i --)

//#define int long long
const int MAXN = 10005;
struct edge {
  int v, w;
};

struct node {
  int dis, u;

  bool operator>(const node& a) const { return dis > a.dis; }
};

vector<edge> e[MAXN];
int dis[MAXN], vis[MAXN];
priority_queue<node, vector<node>, greater<node>> q;

void dijkstra(int n, int s) {
  memset(dis, 0x3f, (n + 1) * sizeof(int));
  memset(vis, 0, (n + 1) * sizeof(int));
  dis[s] = 0;
  q.push({0, s});
  while (!q.empty()) {
    int u = q.top().u;
    q.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (auto ed : e[u]) {
      int v = ed.v, w = ed.w;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        q.push({dis[v], v});
      }
    }
  }
}

void solve() {
    int n, m; std::cin >> n >> m;
    while (m --) {
        int u, v, w; std::cin >> u >> v >> w;
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


4 6 1 4
1 2 2
1 3 4
1 4 7
2 3 1
2 4 3
3 4 9


*/