/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-29 14:47:26
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#include <bits/stdc++.h>

using ll = long long;

const ll INF = 0x3f3f3f3f3f3f3f3f;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int n, m, s, t;
    std::cin >> n >> m >> s >> t;
    
    std::vector<int> head(n + 1, -1);
    struct edge {
        int to; int nxt;
        int w;
    };
    std::vector<edge> g(2 * m + 10);
    int ttt = 1;
    auto addedge = [&](int u, int v, int w) -> void {
        g[ttt].to = v; g[ttt].w = w;
        g[ttt].nxt = head[u]; head[u] = ttt ++;
    };
    
    int __ = m;
    while (__ --) {
        int u, v, w;
        std::cin >> u >> v >> w;
        addedge(u, v, w);
        addedge(v, u, w);
    }
    
    std::vector<ll> dis(n + 1, INF);
    auto dijkstra = [&](int s) -> void {
        struct node {
            ll id; ll dd;
            bool operator < (const node &a) const {
                return dd > a.dd;
            }
        };
        std::priority_queue<node> pq;
        dis[s] = 0;
        pq.push({s, dis[s]});
        
        while (!pq.empty()) {
            auto pii = pq.top();
            pq.pop();
            
            for (int i = head[pii.id]; i != -1; i = g[i].nxt) {
                int v = g[i].to; int wei = g[i].w;
                
                if (dis[v] > dis[pii.id] + wei) {
                    dis[v] = dis[pii.id] + wei;
                    pq.push({v, dis[v]});
                }
            }
        }
    };
    
    dijkstra(s);
    
    if (dis[t] == INF) {
        std::cout << -1 << '\n';
    } else {
        std::cout << dis[t] << '\n';
    }
    
    return 0;
}