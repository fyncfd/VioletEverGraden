/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-12 12:39:14
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#define  _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O2")
#include "bits/stdc++.h"
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using ldb = long double;
typedef __int128 i128;
typedef unsigned __int128 u128;

const double eps = 1e-9;
constexpr int INF = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr i64 mod = 998244353;
constexpr i64 MOD = 1e9 + 7;
constexpr int MAXN = 0;

/*
* @Author: AlgoStruggler
* SgementTree + Lazy_tag Info, tag类型支持拓展操作。
* 模板把数据的操作全部交给Info自行计算并合并，然后即可在Query中取出。
* 线段树本身不理解Info中存储的数据。
* @Create Time: 2026-01-27 17:06:11
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
* 愿幸运女神与最纯粹的前行者同在。
*/
template <typename Info, typename Tag, typename T = i64>
class LazySegmentTree {
private:
	int N;
	std::vector<i64> a;
	std::vector<Info> Seg;
	std::vector<Tag> Lazy;

	void push_up(i64 id) {
		Seg[id] = Seg[id << 1] + Seg[id << 1 | 1];
	}

	void Build(i64 id, i64 l, i64 r) {
		Lazy[id] = Tag();
		if (l == r) {
			Seg[id] = Info(a[l], 1);
		} else {
			i64 mid = l + r >> 1;
			Build(id << 1, l, mid);
			Build(id << 1 | 1, mid + 1, r);
			push_up(id);
		}
	}

    void ApplyTag(i64 id, const Tag &t) {
        Seg[id].ApplyTag(t);
        Lazy[id].ApplyTag(t);
    }

	void push_down(i64 id) {
        ApplyTag(id << 1, Lazy[id]);
        ApplyTag(id << 1 | 1, Lazy[id]);
        Lazy[id] = Tag();
	}

    void Update(i64 id, i64 l, i64 r, i64 pos, const Tag &v) {
        if (l == r) {
            ApplyTag(id, v);
            return;
        }
        push_down(id);

        i64 mid = l + r >> 1;
        if (pos <= mid) {
            Update(id << 1, l, mid, pos, v);
        } else {
            Update(id << 1 | 1, mid + 1, r, pos, v);
        }
        push_up(id);
    }

	void Modify(i64 id, i64 l, i64 r, i64 ql, i64 qr, const Tag &v) {
    	if (l >= ql and r <= qr) {
    		ApplyTag(id, v);
    		return ;
    	}
        push_down(id);

        i64 mid = l + r >> 1;
        if (ql <= mid) {
            Modify(id << 1, l, mid, ql, qr, v);
        }
        if (qr > mid) {
            Modify(id << 1 | 1, mid + 1, r, ql, qr, v);
        }
        push_up(id);
	}

	Info Query(i64 id, i64 l, i64 r, i64 ql, i64 qr) {
    	if (ql <= l and qr >= r) {
    		return Seg[id];
    	}
    	push_down(id);

    	i64 mid = l + r >> 1;
    	if (qr <= mid) {
    		return Query(id << 1, l, mid, ql, qr);
    	} 
    	if (ql > mid) {
    		return Query(id << 1 | 1, mid + 1, r, ql, qr);
    	}
    	return Query(id << 1, l, mid, ql, qr) + Query(id << 1 | 1, mid + 1, r, ql, qr);
	}
public:
    LazySegmentTree(const std::vector<T> &arr) {
        a = arr;
        N = (int)arr.size() - 1;
        Seg.resize(N << 2);
        Lazy.resize(N << 2);
        Build(1, 1, N);
    }

    void Update(i64 pos, const Tag &v) {
    	return Update(1, 1, N, pos, v);
    }

    void Modify(i64 l, i64 r, const Tag &v) {
    	return Modify(1, 1, N, l, r, v);
    }

    Info Query(i64 l, i64 r) {
    	return Query(1, 1, N, l, r);
    }
};

struct Tag {
	i64 ass;
	bool ok;
	Tag(i64 a = 0, bool t = false) : ass(a), ok(t) {}

	void ApplyTag(const Tag &t) {
		if (t.ok) {
			ass = t.ass;
		}
	}
};

struct Info {
    i64 sum;
    i64 pre;
    i64 suf;
    i64 max;
    i64 len;

    Info(i64 v = 0, i64 l = 1) {
        sum = v;
        pre = v;
        suf = v;
        max = v;
        len = l;
    }

    Info operator + (const Info &a) const {
        Info res;
        res.sum = sum + a.sum;
        res.pre = std::max(pre, sum + a.pre);
        res.suf = std::max(a.suf, a.sum + suf);
        res.max = std::max({max, a.max, suf + a.pre});
        res.len = len + a.len;
        return res;
    }

    void ApplyTag(const Tag &t) {
        if (t.ok) {
            sum = t.ass * len;
            pre = t.ass * len;
            suf = t.ass * len;
            max = t.ass * len;
        }
    }
};

static inline void VioletEverGraden() {
    int n, m;
    std::cin >> n >> m;

    std::vector<i64> a(n + 1);
    for (int i = 1; i <= n; i ++) {
    	std::cin >> a[i];
    }

    LazySegmentTree<Info, Tag> Lseg(a);
    while (m --) {
    	int op;
    	std::cin >> op;

    	if (op == 1) {
    		int l, r;
    		std::cin >> l >> r;
    		if (l > r) {
    			std::swap(l, r);
    		}
    		i64 ans = Lseg.Query(l, r).max;
    		std::cout << ans << '\n';
    	} else {
    		int pos, s;
    		std::cin >> pos >> s;
    		Lseg.Update(pos, Tag(s, true));
    	}
    }
    
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

5 3
1
2
-3
4
5
1 2 3
2 2 -1
1 2 3

2
-1


*/
}

signed main() {
#ifdef Algostruggler
    freopen("A.in", "r", stdin);
#endif // Algostruggler

    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    /*std::cout << std::fixed << std::setprecision(9);
    std::cerr << std::fixed << std::setprecision(9);*/

    int _ = 1;
    //for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}