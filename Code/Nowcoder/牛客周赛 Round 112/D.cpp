#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 998244353;
const int MAXN = 200005;

ll pow2[MAXN];
int cnt[MAXN];
ll f[MAXN];

void precompute() {
    pow2[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        pow2[i] = (pow2[i-1] * 2) % MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    precompute();
    
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        
        vector<int> a(n+1);
        vector<int> freq(n+1, 0);
        
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }

        fill(cnt, cnt + n + 1, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                cnt[i] += freq[j];
            }
        }

        ll bad = 0;
        for (int g = n; g >= 1; g--) {
            if (cnt[g] == 0) continue;

            f[g] = pow2[cnt[g] - 1];

            for (int k = 2 * g; k <= n; k += g) {
                f[g] = (f[g] - f[k] + MOD) % MOD;
            }

            if (freq[g] > 0) {
                bad = (bad + f[g]) % MOD;
            }
        }

        ll total = (pow2[n] - 1 + MOD) % MOD;
        ll ans = (total - bad + MOD) % MOD;
        
        cout << ans << '\n';
    }
    
    return 0;
}