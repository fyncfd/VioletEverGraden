#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> C(n);
        unordered_map<int, int> cnt;
        bool has_dup = false;
        for (int i = 0; i < n; ++i) {
            cin >> C[i];
            if (cnt[C[i]]++ > 0)
                has_dup = true;
        }
        if (has_dup || n > m) {
            cout << "YES\n";
            continue;
        }
        bool found = false;
        unordered_map<int, vector<pair<int, int>>> sum_map;
        for (int i = 0; i < n && !found; ++i) {
            for (int j = i + 1; j < n && !found; ++j) {
                int s = C[i] + C[j];
                auto& vec = sum_map[s];
                for (auto& p : vec) {
                    if (p.first != i && p.first != j && p.second != i && p.second != j) {
                        found = true;
                        break;
                    }
                }
                vec.emplace_back(i, j);
            }
        }
        cout << (found ? "YES" : "NO") << '\n';
    }
    return 0;
}