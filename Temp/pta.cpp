#include <bits/stdc++.h>

using i64 = long long;

const int MAXN = 100000;
std::map<std::string, std::string> fa[MAXN];
int sz[MAXN];

void init() {
	for (int i = 0; i < MAXN; i ++) {
		fa[i] = i;
		sz[i] = 0;
	}
}

std::string find(int x) {
	if (fa[x] == x) {
		return fa[x];
	} 
	return find(fa[x]);
}

void merge(int x, int y) {
	int rx = find(x); int ry = find(y);
	if (rx != ry) {
		fa[rx] = ry;
		sz[y] += sz[x];
	}
}

void solve() {
	int N;
	std::cin >> N;

	int __ = N;
	while (__ --) {
		int id, p1, p2, k;
		std::cin >> id >> p1 >> p2 >> k;
		if (p1 != -1) {
			merge()
		}
		std::vector<int> son(k + 1);
		for (int i = 1; i <= k; i ++) {
			std::cin >> son[i];
		}


	}
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int _ = 1;
//	for (std::cin >> _; _; _ --)
		solve();
		
	return 0;
}
