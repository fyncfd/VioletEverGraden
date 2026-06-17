#include <bits/stdc++.h>

using ll = long long;
#define rep(i, l, r, x) for (int i = l; i <= r; i += x)
constexpr int INF = 0x3f3f3f3f;
const int MAXN = 0;


void violet() {
    int n, m, s;
    std::cin >> n >> m >> s;

    int tot = 1;
    std::vector<int> head(n + 1, -1);
    struct Edge {
        int to; int nxt; int w;
    };
    std::vector<Edge> G(2 * m + 10);
    auto AddEdge = [&](int u, int v, int w = 0) -> void {
        G[tot].to = v;
        G[tot].w = w;
        G[tot].nxt = head[u];
        head[u] = tot ++;
    };

    int __ = m;
    while (__ --) {
        int u, v, w;
        std::cin >> u >> v >> w;
        AddEdge(u, v, w);
    }

    std::vector<int> dis(n + 1, INF);
    auto Dijkstra = [&](int s) -> void {
        dis[s] = 0;
        struct node {
            int id; int d;
            bool operator < (const node &a) const {
                return d > a.d;
            }
        };
        std::priority_queue<node> heap;
        heap.push({s, dis[s]});

        while (!heap.empty()) {
            auto [u, d] = heap.top();
            heap.pop();

            if (d > dis[u]) continue;
            for (int i = head[u]; ~i; i = G[i].nxt) {
                int v = G[i].to; int w = G[i].w;
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    heap.push({v, dis[v]});
                }
            }
        }
    };

    Dijkstra(1);

    rep(i, 1, n, 1) {
        std::cout << dis[i] << " \n"[i == n];
    }

/*
Test Sample
4 6 1
1 2 2
2 3 2
2 4 1
1 3 5
3 4 3
1 4 4

0 2 4 3
*/
}

signed main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout.tie(nullptr);

    int _ = 1;
    // for (std::cin >> _; _; _ --)
        violet();
        
    return 0;
}