#include "bits/stdc++.h"

using i64 = long long;
using i128 = __int128;
 
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;

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
	i64 add;
	Tag(i64 a = 0) : add(a) {}

	void ApplyTag(const Tag &t) {
		add += t.add;
	}
};

struct Info {
	i64 sum;
	i64 len;
	Info(i64 s = 0, i64 l = 1) : sum(s), len(l) {}

	Info operator + (const Info &a) const {
		Info res;
		res.sum = sum + a.sum;
		// res.max = std::max(max, a.max)
		res.len = len + a.len;
		return res;
	}

	void ApplyTag(const Tag &t) {
		sum += t.add * len;
	}
};

void VioletEverGraden() {
	int n, m;
	std::cin >> n >> m;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i];
	}

	LazySegmentTree<Info, Tag> Seg(a);
	int __ = m;
	while (__ --) {
		int op;
		std::cin >> op;

		if (op == 1) {
			i64 l, r, k;
			std::cin >> l >> r >> k;
			Seg.Modify(l, r, {k});
		} else {
			i64 l, r;
			std::cin >> l >> r;
			i64 ans = Seg.Query(l, r).sum;
			std::cout << ans << '\n';
		}
	}

/*
Test Sample

4 5
6 2 4 5
1 1 2 5
1 1 4 2
2 1 4
1 3 3 -8
2 3 4

35
5

5 5
1 5 4 2 3
2 2 4
1 2 3 2
2 3 4
1 1 5 1
2 1 4

11
8
20


*/
}

signed main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

	int _ = 1;
    // for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}