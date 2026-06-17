/*
* @Author: AlgoStruggler
* @Create Time: 2026-03-29 14:32:38
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#pragma GCC optimize("O3,unroll-loops,Ofast,inline")
#include "bits/stdc++.h"

using i64 = int64_t;
using i128 =  __int128_t;

using u32 = uint32_t;
using u64 = uint64_t;
using u128 = __uint128_t;

using f32 = float;
using f64 = double;
using f80 = long double;

constexpr int INF = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr i64 mod = 998'244'353LL;
constexpr i64 MOD = 1e9 + 7;

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
        if (l >= ql && r <= qr) {
            ApplyTag(id, v);
            return;
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
        if (ql <= l && qr >= r) return Seg[id];
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

    int FindLeft(int id, int l, int r, int pos) {
        if (r < 1 || l > pos) 
        	return 0;
        if (l == r) 
        	return Seg[id].max == 1 ? l : 0;
        push_down(id);
        int mid = (l + r) >> 1;
        int res = 0;
        if (pos > mid) {
            res = FindLeft(id << 1 | 1, mid + 1, r, pos);
            if (res) {
            	return res;
            }
        }
        return FindLeft(id << 1, l, mid, pos);
    }

    int FindRight(int id, int l, int r, int pos) {
        if (l > N || r < pos) {
        	return N + 1;
        }
        if (l == r) {
        	return Seg[id].max == 1 ? l : N + 1;
        }
        push_down(id);
        int mid = (l + r) >> 1;
        int res = N + 1;
        if (pos <= mid) {
            res = FindRight(id << 1, l, mid, pos);
            if (res != N + 1) {
            	return res;
            }
        }
        return FindRight(id << 1 | 1, mid + 1, r, pos);
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
        Update(1, 1, N, pos, v);
    }

    void Modify(i64 l, i64 r, const Tag &v) {
        Modify(1, 1, N, l, r, v);
    }

    Info Query(i64 l, i64 r) {
        return Query(1, 1, N, l, r);
    }

    int find_left(int pos) {
        return FindLeft(1, 1, N, pos);
    }

    int find_right(int pos) {
        return FindRight(1, 1, N, pos);
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
    i64 max;
    i64 sum;
    i64 len;
    Info(i64 mx = 0, i64 s = 0, i64 l = 1) : max(mx), sum(s), len(l) {}

    Info operator + (const Info &a) const {
        Info res;
        res.max = std::max(max, a.max);
        res.sum = sum + a.sum;
        res.len = len + a.len;
        return res;
    }

    void ApplyTag(const Tag &t) {
        sum += t.add * len;
        max += t.add;
    }
};

static inline void VioletEverGraden() {
    int n;
    std::cin >> n;

    std::vector<int> a(n + 1);
    std::vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        pos[a[i]] = i;
    }

    std::vector<i64> init(n + 1, 0);
    LazySegmentTree<Info, Tag> Seg(init);

    i64 ans = 0;

    for (int v = n; v >= 1; v--) {
        int p = pos[v];
        int L = Seg.find_left(p);
        int R = Seg.find_right(p);

        int lo = std::max({1, p - v + 1, L + 1});
        int hi = std::min({p, n - v + 1, R - v});

        if (lo <= hi) {
            ans += hi - lo + 1;
        }

        Seg.Update(p, Tag(1));
    }

    std::cout << ans << '\n';
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

*/
}

signed main() {
#ifdef Algostruggler
    freopen("A.in", "r", stdin);
#endif // Algostruggler

    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    // std::cout << std::fixed << std::setprecision(12), std::cerr << std::fixed << std::setprecision(12);

    for (int _ = [&]() -> int { int T; std::cin >> T; return T; }(); _; _ --)
        VioletEverGraden();

    return 0;
}