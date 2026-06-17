#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (auto &x : a) cin >> x;

        int ans = 0;

        for (int i = 1; i < n; i++) {
            if (a[i] < a[i - 1]) {
                ans++;
                a[i] = a[i - 1]; // 修改为前一个值
            }
        }

        cout << ans << '\n';
    }

    return 0;
}