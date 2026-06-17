#include "bits/stdc++.h"

using i64 = long long;
using i128 = __int128;
 
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;

/*
* Fenwick 封装类。
* @Author: AlgoStruggler
* @Create Time: 2026-02-01 18:16:19
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
* 愿幸运女神与最纯粹的前行者同在。
*/
template <typename T>
class Fenwick {
private:
	int N;
	std::vector<i64> BIT;
	inline i64 lowbit(i64 x) {
		return x & -x;
	}

    T getSum(int pos) {
        T res = 0;
        while (pos > 0) {
            res += BIT[pos];
            pos -= lowbit(pos);
        }
        return res;
    }
public:
    Fenwick(int n = 0) : N(n), BIT(n + 1, 0) {}
    
    Fenwick(const std::vector<T> &arr) {
        N = arr.size() - 1;
        BIT.assign(N + 1, 0);
        
        std::vector<T> prefix(N + 1, 0);
        for (int i = 1; i <= N; i++) {
            prefix[i] = prefix[i - 1] + arr[i];
            BIT[i] = prefix[i] - prefix[i - lowbit(i)];
        }
    }

    void Update(int pos, T Val) {
        while (pos <= N) {
            BIT[pos] += Val;
            pos += lowbit(pos);
        }
    }

    T rangeSum(int L, int R) {
        return getSum(R) - getSum(L - 1);
    }

    T getVal(int pos) {
        return rangeSum(pos, pos);
    }

    void setVal(int pos, i64 Val) {
        i64 Cur = getVal(pos);
        i64 Dif = Val - Cur;
        Update(pos, Dif);
    }

    int size() const {
        return N;
    }

    void clear() {
        std::fill(BIT.begin(), BIT.end(), 0);
    }
};

void VioletEverGraden() {
	int n, m;
	std::cin >> n >> m;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i];
	}

	Fenwick<i64> Fen(a);
	int __ = m;
	while (__ --) {
		int op;
		std::cin >> op;

		if (op == 1) {
			int x, k;
			std::cin >> x >> k;
			Fen.Update(x, k);
		} else {
			int l, r;
			std::cin >> l >> r;
			i64 ans = Fen.rangeSum(l, r);
			std::cout << ans << '\n';
		}
	}

/*
Test Sample

5 5
1 5 4 2 3
1 1 3
2 2 5
1 3 -1
1 4 2
2 1 4

14
16


*/
}

signed main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

	int _ = 1;
    // for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}