#include <bits/stdc++.h>

using ll = long long;

#define rep(i, l, r, x) for (int i = l; i <= r; i += x)
#define dep(i, l, r, x) for (int i = l; i >= r; i -= x)

int n;
std::vector<int> a;
void violet() {
	std::cin >> n;
	a.resize(n + 2, -1);
	std::unordered_map<int, int> hash;
	rep(i, 1, n, 1) {
		std::cin >> a[i];
		hash[a[i]] ++;
	}

	std::vector<int> num;
	int pos = 1;
	rep(i, 1, n, 1) {
		if (a[i] != a[i + 1]) {
			num.push_back(i - pos + 1);
			pos = i + 1;
		}
	}

	for (auto pii : hash) {
		if (pii.second % 2 == 0) {
			std::cout << "No\n";
			return ;
		}
	}

	bool ok = false;
	for (auto x : num) {
		if (x % 2 == 0) {
			ok = true;
			break;
		} 
	}

	if (ok) {
		std::cout << "No\n";
	} else {
		std::cout << "Yes\n";
	}

/*	for (auto x : num) {
		std::cout << x << ' ';
	}
	std::cout << std::endl;*/
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int _ = 1;
	for (std::cin >> _; _; _ --) 
		violet();

	return 0;
}

/*
3
3
1 2 1
5
1 1 1 2 3
7
2 2 2 2 2 2 2
*/