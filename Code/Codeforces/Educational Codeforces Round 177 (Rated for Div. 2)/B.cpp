#include <bits/stdc++.h>

using ll = long long;

int n, k; ll x;

void solve() {
    std::cin >> n >> k >> x;
    std::vector<ll> a(n);
    for (auto &num : a) {
    	std::cin >> num;
    }
    
    std::vector<ll> suf(n + 2, 0);
    for (int i = n; i >= 1; i --) {
        suf[i] = a[i - 1] + suf[i + 1];
    }
    ll s = suf[1];
    ll temp = s * k;
    if (temp < x) {
        std::cout << "0\n";
        return ;
    }
    
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll sum = suf[i];
        if (sum >= x) {
            ans += k;
        } 
        else {
            ll rem = x - sum;
            if (rem <= 0) {
                ans += k;
                return ;
            }
            ll cnt = (rem + s - 1) / s;
            ll can = k - cnt;
            if (can > 0) {
                ans += can;
            }
        }
    }
    std::cout << ans << '\n';
}

signed main() {
	std::cin.tie(nullptr) ->
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int _ = 1;
	std::cin >> _;

	while (_ --) {
		solve();
	}

	return 0;
}