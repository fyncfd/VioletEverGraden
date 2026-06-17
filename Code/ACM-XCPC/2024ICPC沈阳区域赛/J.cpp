#include "bits/stdc++.h"

using ll = long long;
using ull = unsigned long long;
using namespace std;

#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define red(i, l, r) for (int i = l; i >= r; i --)

//define int long long
struct que {
	std::string name;
	int pow;
}a[9];

void solve() {
    for (int i = 1; i <= 8; i++) {
        cin >> a[i].name >> a[i].pow;
    }

    vector<que> cnt;
    for (int i = 1; i <= 7; i += 2) {
        if (a[i].pow > a[i + 1].pow) {
            cnt.push_back(a[i]);
        } else {
            cnt.push_back(a[i + 1]);
        }
    }

    vector<que> ans;
    for (int i = 0; i <= 2; i += 2) {
        if (cnt[i].pow > cnt[i + 1].pow) {
            ans.push_back(cnt[i]);
        } else {
            ans.push_back(cnt[i + 1]);
        }
    }

    if (ans[0].pow > ans[1].pow) {
        cout << ans[0].name << " beats " << ans[1].name << '\n';
    } else {
        cout << ans[1].name << " beats " << ans[0].name << '\n';
    }
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