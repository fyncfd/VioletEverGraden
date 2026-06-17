#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 998244353;

ll mod_pow(ll a, ll b) {
    ll res = 1;
    for (a %= MOD; b; b >>= 1, a = a * a % MOD)
        if (b & 1) res = res * a % MOD;
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> freq;
    for (int &x : a) {
        cin >> x;
        freq[x]++;
    }
    
    ll A = (n + 1) % MOD * mod_pow(2, n - 2) % MOD;
    ll B = 0;
    
    for (auto &[col, cnt_i] : freq) {
        vector<int> others;
        for (auto &[c, f] : freq) {
            if (c == col) continue;
            others.push_back(f);
        }
        int m = others.size();
        
        for (int k = 1; k <= cnt_i; ++k) {
            vector<ll> dp(k, 0);
            dp[0] = 1;
            for (int f : others) {
                int lim = min(k, f);
                vector<ll> ndp(k, 0);
                for (int s = 0; s < k; ++s) {
                    if (dp[s] == 0) continue;
                    for (int t = 0; t <= lim; ++t) {
                        if (s + t >= k) continue;
                        ndp[s + t] = (ndp[s + t] + dp[s]) % MOD;
                    }
                }
                dp = move(ndp);
            }
            
            for (int s = 0; s < k; ++s) {
                ll ways = dp[s];
                if (ways == 0) continue;
                int ctri = (k - (k + s + 1)/2) % MOD;
                B = (B + 1LL * ctri * ways % MOD * mod_pow(2, cnt_i - k) % MOD) % MOD;
            }
        }
    }
    
    B = (B % MOD + MOD) % MOD;
    ll total = (A + B) % MOD;
    cout << total << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}