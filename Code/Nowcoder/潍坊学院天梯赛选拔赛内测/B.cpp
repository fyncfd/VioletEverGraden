#include <bits/stdc++.h>

using namespace std;

#define rep(i, l, r) for(int i = l; i <= r; i ++)
#define red(i, l, r) for(int i = l; i >= r; i --)

int n;
int a[105][105];

void solve() {
	std::cin >> n;
	rep(i, 1, n) {
		rep(j, 1, n) {
			std::cin >> a[i][j];
		}
	}

	rep(i, 1, n / 2) {
		int num0 = 0; int num1 = 0;
		rep(j, 1, n / 2) {
			num0 = (a[i][j] == 0) + (a[])
		}
	}
}