#include "bits/stdc++.h"

using ll = long long;
using ull = unsigned long long;


#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define red(i, l, r) for (int i = l; i >= r; i --)
#define lop(i, x) for (auto i : x)


//#deifne int long long;
int n;
int a[300005];

void solve() {
	std::cin >> n;
	std::map<int, int> mp;
	std::set<int> st;
	rep(i, 1, n) {
		std::cin >> a[i];
		mp[a[i]] ++;
		st.insert(a[i]);
	}

	bool ok = false;
	lop(x, mp) {
		if (x.second >= 2) {
			ok = true;
			break;
		}
	}

	if (ok) {
		std::cout << st.size() + 1 << '\n';
		return ;
	}
	std::cout << st.size() << '\n';
}	

signed main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	std::cout.tie(nullptr);

	int _ = 1;
	//std::cin >> _;

	while (_ --) {
		solve();
	}

	return 0;
}