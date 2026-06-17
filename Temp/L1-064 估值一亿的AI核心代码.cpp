/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-24 15:25:48
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#include <bits/stdc++.h>

using i64 = long long;

const int INF = 0x3f3f3f3f;

int main() {
    int N, M, S, D;
    std::cin >> N >> M >> S >> D;

    std::vector<int> num(N + 1);
    for (int i = 1; i <= N; i ++) {
        std::cin >> num[i];
    }

    int tot = 1;
    std::vector<int> head(N + 1, -1);
    struct Edge {
        int to; int nxt; int w;
    };
    std::vector<Edge> G(2 * M + 10);
    auto AddEdge = [&](int u, int v, int w) -> void {
        G[tot].to = v;
        G[tot].nxt = head[u];
        G[tot].w = w;
        head[u] = tot ++;
    };

    int __ = M;
    while (__ --) {
        int u, v, w;
        std::cin >> u >> v >> w;
        AddEdge(u + 1, v + 1, w);
        AddEdge(v + 1, u + 1, w);
    }

    std::vector<int> dis(N + 1, INF);
    std::vector<int> cnt(N + 1, 0);
    std::vector<int> fa(N + 1, -1);
    std::vector<int> st(N + 1, 0);

    std::vector<bool> vis(N + 1, false);

    auto Dijkstra = [&](int s) -> void {
        dis[s] = 0;
        st[s] = 1;
        cnt[s] = num[s];

        struct Node {
            int id; int d;
            bool operator < (const Node &a) const {
                return d > a.d;
            }
        };

        std::priority_queue<Node> heap;
        heap.push({s, dis[s]});

        while (!heap.empty()) {
            auto x = heap.top();        
            heap.pop();

            if (x.d < dis[x.id] || vis[x.id]) {
                continue;
            }
            vis[x.id] = true;

            int u = x.id;
            for (int i = head[u]; ~i; i = G[i].nxt) {
                int v = G[i].to;
                int w = G[i].w;

                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    cnt[v] = cnt[u] + num[v];
                    fa[v] = u;
                    st[v] = st[u];
                    heap.push({v, dis[v]});
                } else if (dis[v] == dis[u] + w) {
                    st[v] += st[u];
                    if (cnt[u] + num[v] > cnt[v]) {
                        dis[v] = dis[u] + w;
                        fa[v] = u;
                        cnt[v] = cnt[u] + num[v];
                        heap.push({v, dis[v]});
                    }
                }
            }
        }
    };

    Dijkstra(S + 1);

    std::vector<int> path;
    for (int i = D + 1; ~i; i = fa[i]) {
        path.push_back(i - 1);
    }

    std::reverse(path.begin(), path.end());

    std::cout << st[D + 1] << ' ' << cnt[D + 1] << '\n';
    for (int i = 0; i < path.size(); i ++) {
        std::cout << path[i] << " \n"[i + 1 == path.size()];
    }

    return 0;
}
// zzz zzy ... zyz zxz zwz... 