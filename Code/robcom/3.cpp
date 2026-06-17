#include <bits/stdc++.h>

using ll = long long;

#define rep(i, l, r, x) for (int i = l; i <= r; i += x)


void violet() {
	std::string s1;
	std::cin >> s1;
	std::string s2;
	std::cin.ignore();
	std::cin >> s2;

	std::vector<char> st;
	

	ll ans = 0;
	char c1 = s1[0]; char c2 = s1[1];
	for (int i = 0; i < s2.size(); i ++) {
		if (st.empty()) {
			st.push_back(s2[i]);
		} else {
			if (s2[i] == c1) {
				st.push_back(s2[i]);
			} else if (s2[i] == c2) {
				if (st.back() == c1) {
					st.pop_back();
					ans ++;
				} else {
					st.push_back(s2[i]);
				}
			} else {
				st.push_back(s2[i]);
			}
		}

	}
	std::cout << ans << ' ';

	for (int i = 0; i < st.size(); i ++) {
		std::cout << st[i];
	}
	std::cout << '\n';
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int _ = 1;
	//for (std::cin >> _; _; _ --)
		violet();

	return 0;
}