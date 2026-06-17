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
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        string s;
        cin >> s;

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '<') {
                if (a[i] >= 0) {
                    ans++;
                    a[i] = -1;
                }
            } 
            else if (s[i] == '>') {
                if (a[i] <= 0) {
                    ans++;
                    a[i] = 1;
                }
            } 
            else if (s[i] == 'Z') {
                if (i == 0) {
                	continue;
                }
                if (a[i-1] * a[i] <= 0) {
                    ans++;
                    if (a[i-1] > 0) {
                        a[i] = 1;
                    } 
                    else {
                        a[i] = -1;
                    }
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}