#include <bits/stdc++.h>

int a, b, c;

signed main() {
	std::cin >> a >> b >> c;

	if (a > b and b < c) {
		std::cout << "YES\n";
		return 0;
	}
	std::cout << "NO\n";

	return 0;
}
/*
3 1 3

YES

1 2 3

NO

*/