/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-17 11:03:21
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;

    struct Node {
        int id;
        std::vector<int> son;
    };
    std::vector<Node> tree(n + 1);

    int root = 0;
    std::vector<int> deg(n + 1, 0);
    for (int i = 1; i <= n; i ++) {
        int fa;
        std::cin >> fa;
        deg[fa] ++;
        // deg[i] ++;
        if (fa == 0) {
            root = i;
        } else {
            tree[fa].son.push_back(i);
        }
    }

/*    for (int i = 1; i <= n; i ++) {
        std::cerr << "deg:" << deg[i] << " \n"[i == n];
    }*/

    int k = 0;
    for (int i = 1; i <= n; i ++) {
        k = std::max(k, deg[i]);
    }

    bool ok = true;
    for (int i = 1; i <= n; i ++) {
        if (deg[i] != 0 && deg[i] != k) {
            ok = false;
        }
    }

    std::cout << k << ' ';
    if (ok) {
        std::cout << "yes\n";
    } else {
        std::cout << "no\n";
    }

    std::vector<int> ans;
    auto dfs = [&](auto &&dfs, int u) -> void {
        // std::cout << u << '\n';
        ans.push_back(u);
        for (int i = 0; i < tree[u].son.size(); i ++) {
            int v = tree[u].son[i];
            dfs(dfs, v);
        }
    };

    dfs(dfs, root);

    for (int i = 0; i < ans.size(); i ++) {
        std::cout << ans[i] << " \n"[i + 1 == ans.size()];
    }

    return 0;
}

namespace ksm {
    template <typename T = ll>
    class ksm {
        public:
            T fastpow(T a, T b) {//迭代法求快速幂，避免溢出
                T res = 1;
                while (b > 0) {
                    if (b & 1) {
                        res *= a;
                    }
                    a *= a;
                    b >>= 1;
                }
                return res;
            }
            T powmod(T a, T b, T m) {//迭代法求取模快速幂
                a %= m;//先取模，确保a < m;
                T res = 1;
                while (b > 0) {
                    if (b & 1) {
                        res = (res * a) % m;
                    }
                    a = (a * a) % m;//平方后取模
                    b >>= 1;
                }
                return res;
            }
    };
}4