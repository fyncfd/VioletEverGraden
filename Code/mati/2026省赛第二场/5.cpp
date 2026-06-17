#include<bits/stdc++.h> 

using i64 = long long;

#define int long long

using u64 = unsigned long long;

template <typename T>
class LB {
private:
    static constexpr int BASE = sizeof(T) * 8;
    std::vector<T> BA;
    std::vector<u64> BAM;

public:
    LB() {
        BA.assign(BASE, T{0});
        BAM.assign(BASE, 0);
    }

    bool Insert(T val, int id) {
        // u64 cur = 0;
        for (int i = BASE - 1; i >= 0; i --) {
            if ((val >> i) & 1) {
                if (!BA[i]) {
                    BA[i] = val;
                    // BAM[i] = cur | (1ULL << )
                    return true;
                }
                val ^= BA[i];
                // cur ^= BAM[i];
            }
        }
        return false;
    }

    T MV(T x) const {
        T res = x;
        for (int i = BASE - 1; i >= 0; i --) {
            if ((res ^ BA[i]) > res) {
                res ^= BA[i];
            }
        }

        return res;
    } 
};

constexpr int N = 500025;

int fa[N + 100];
int sz[N + 100];

void init() {
    for (int i = 1; i <= N; i ++) {
        fa[i] = i;
        sz[i] = 1;
    }
}

int find(int x) {
    while (x != fa[x]) {
        x = fa[x] = fa[fa[x]];
    }
    return x;
}

void merge(int x, int y) {
    int rx = find(x); int ry = find(y);
    if (rx != ry) {
        fa[rx] = ry;
        sz[ry] += sz[rx];
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    init();

    LB<i64> lb;

    for (int i = 1; i <= m; i ++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        // return 0;
        merge(u, v);
        i64 z = w ^ (u ^ v);
        lb.Insert(z, -1);
    }

    int q;
    std::cin >> q;
    int __ = q;
    while (__ --) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int x, y;
            std::cin >> x >> y;
            if (x == y) {
                if (sz[find(x)] == 1) {
                    std::cout << 0 << '\n';
                    continue;
                }
            }
            if (find(x) != find(y)) {
                std::cout << -1 << '\n';
                continue;
            }
            i64 it = (x ^ y);
            i64 ans = lb.MV(it);
            std::cout << ans << '\n';
        } else {
            int x, y, z;
            std::cin >> x >> y >> z;
            merge(x, y);
            i64 f = z ^ (x ^ y);
            lb.Insert(f, -1);
        }
    }

    return 0;
}