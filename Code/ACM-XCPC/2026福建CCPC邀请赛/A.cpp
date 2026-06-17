#include <bits/stdc++.h>

using namespace std;

int main() {
	int T = 1;
	std::cin >> T;

	while (T --) {
		int n, m;
		std::cin >> n  >> m;

		int ans1 = 0;
		int t = n - m;
		if (t % 3 == 0) {
			ans1 = m / 3 + (m % 3 != 0);
		} else {
			int x = t % 3, y = m % 3;
			if (x + y > 3) {
				ans1 = m / 3 + (m % 3 != 0);
			} else {
				ans1 = m / 3;
			}
		}

		int ans2 = m / 6;
		ans2 = std::min(ans2, n / 10 + (n % 10 != 0));

		std::cout << ans1 << ' ' << ans2 << '\n';
	}

	return 0;
}