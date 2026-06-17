#include "bits/stdc++.h"

using i64 = long long;

/*
* DSU封装类，启发式合并，根据集合大小去合并，带路径压缩。
* @Author: AlgoStruggler
* @Create Time: 2026-02-04 15:53:13
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
* 愿幸运女神与最纯粹的前行者同在。
*/
template <typename T>
class DisjointSetUnion {
private:
	int N;
	std::vector<int> Parent;
	std::vector<int> Size;
public:
    DisjointSetUnion(int n) : N(n), Parent(N + 1), Size(N + 1) {
        std::iota(Parent.begin() + 1, Parent.end(), 1);
        Size.assign(N + 1, 1);
    }

    int find(int x) {
    	while (x != Parent[x]) {
    		x = Parent[x] = Parent[Parent[x]];
    	}
    	return x;
    }

    bool same(int x, int y) {
    	return find(x) == find(y);
    }

    bool Merge(int x, int y) {
        int RootX = find(x);
        int RootY = find(y);
        
        if (RootX == RootY) {
            return false;
        }

        if (Size[RootX] < Size[RootY]) {
            std::swap(RootX, RootY);
        }
        
        Parent[RootY] = RootX;
        Size[RootX] += Size[RootY];
        
        return true;
    }

    int size(int x) {
        return Size[find(x)];
    }
};


void VioletEverGraden() {
	int n, q;
	std::cin >> n >> q;

	int __ = q;
	DisjointSetUnion<int> DSU(n); // std::vector<int> A(n + 1);
	while (__ --) {
		int op;
		std::cin >> op;

		if (op == 1) {
			int x, y;
			std::cin >> x >> y;
			DSU.Merge(x, y);
		} else if (op == 2) {
			int x, y;
			std::cin >> x >> y;
			if (DSU.same(x, y)) {
				std::cout << "YES\n";
			} else {
				std::cout << "NO\n";
			}
		} else {
			int x;
			std::cin >> x;
			int ans = DSU.size(x);
			std::cout << ans << '\n';
		}
	}
/*
Test Sample

5 7
1 1 2
1 3 4
2 1 3
3 1
1 2 3
3 2
2 2 4

NO
2
4
YES


*/
}

signed main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

	int _ = 1;
    // for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}