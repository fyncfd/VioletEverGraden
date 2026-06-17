#include <bits/stdc++.h>
using namespace std;

using ll = long long;



void solve() {
		
}

signed main() {
	std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int _ = 1;
	//std::cin >> _;

	while (_ --) {
		solve();
	}
	ll n;
	cin >> n;
	ll ans = 0;
	ans = ll(sqrtl(n)) / 2 + ll(sqrtl(n / 2));
	cout<< ans << endl;

	return 0;
}