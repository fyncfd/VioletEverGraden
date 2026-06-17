/*
* @Author: AlgoStruggler
* @Create Time: 2026-01-19 20:21:38
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#define  _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O2")
#include "bits/stdc++.h"
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;

using i64 = long long;
using ldb = long double;
typedef unsigned long long u64;
typedef __int128 i128;
/*----------------------------------SORT_AND_UNIQUE-----------------------------------*/
const double eps = 1e-9;
constexpr int INF = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr i64 mod = 998244353;
constexpr i64 MOD = 1e9 + 7;
constexpr int MAXN = 0;
/*-----------------------------------MY_CODE_BEGIN------------------------------------*/
template <typename T>
class SegmentTree {
private:
    int N;
    std::vector<T> a;

    struct Info {
        i64 max;
        i64 num;
        i64 len;
        Info(i64 m = 0, i64 n = 0, i64 l = 0) : max(m), num(n), len(l) {}

        Info operator + (const Info &a) const {
            Info res;
            res.len = len + a.len;
            res.num = num + a.num;
            res.max = std::max(max, a.max);
            return res;
        }
    };
    std::vector<Info> Seg;

    struct tag {
        i64 add;
        i64 del;
        i64 flip;
        tag() : add(0), del(0), flip(0) {}
        tag(i64 a) : add(a), del(0), flip(0) {}
        tag(i64 a, i64 d, i64 f) : add(a), del(d), flip(f) {}
    };
    std::vector<tag> Lazy;

    void push_up(i64 id) {
        Seg[id] = Seg[id << 1] + Seg[id << 1 | 1];
    }

    void Build(i64 id, i64 l, i64 r) {
        Lazy[id] = {0, 0, 0};
        if (l == r) {
            Seg[id] = {0, 1, 1};
        } else {
            i64 mid = l + r >> 1;
            Build(id << 1, l, mid);
            Build(id << 1 | 1, mid + 1, r);
            push_up(id);
        }
    }

    void Addtag(i64 id, i64 l, i64 r, const tag &v) {
        if (v.del) {
            Seg[id].max = 0;
        }
        if (v.flip) {
            Seg[id].num = Seg[id].len - Seg[id].num;
        }
        if (Seg[id].num != 0) {
            Seg[id].max += v.add;
        }

        Lazy[id].flip ^= v.flip;
        if (v.del) {
            Lazy[id].del = 1;
            Lazy[id].add = v.add;
        } else {
            Lazy[id].add += v.add;
        }
    }

    void push_down(i64 id, i64 l, i64 r) {
        if (Lazy[id].add or Lazy[id].del or Lazy[id].flip) {
            i64 mid = l + r >> 1;
            Addtag(id << 1, l, mid, Lazy[id]);
            Addtag(id << 1 | 1, mid + 1, r, Lazy[id]);
            Lazy[id] = {0};
        }
    }

    void Update(i64 id, i64 l, i64 r, i64 pos, const tag &v) {
        if (l == r) {
            Addtag(id, l, r, v);
            return;
        }

        i64 mid = l + r >> 1;
        if (pos <= mid) {
            Update(id << 1, l, mid, pos, v);
        } else {
            Update(id << 1 | 1, mid + 1, r, pos, v);
        }
        push_up(id);
    }

    void Modify(i64 id, i64 l, i64 r, i64 ql, i64 qr, const tag &v) {
        if (l >= ql and r <= qr) {
            Addtag(id, l, r, v);
            return ;
        }
        push_down(id, l, r);
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

        push_down(id, l, r);
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
    SegmentTree(const std::vector<T> &arr) {
        a = arr;
        N = (int)arr.size() - 1;
        Seg.resize((N << 2) + 10);
        Lazy.resize((N << 2) + 10);
        Build(1, 1, N);
    }

    tag Tag(i64 add, i64 del, i64 flip) {
        return tag(add, del, flip);
    }

    void Update(i64 pos, const tag &v) {
        return Update(1, 1, N, pos, v);
    }

    void Modify(i64 l, i64 r, const tag &v) {
        return Modify(1, 1, N, l, r, v);
    }

    Info Query(i64 l, i64 r) {
        return Query(1, 1, N, l, r);
    }
};

static inline void VioletEverGraden() {
    int N, Q;
    std::cin >> N >> Q;

    SegmentTree<i64> Seg(std::vector<i64> (N + 1, 0));
    int __  = Q;
    while (__ --) {
        int op;
        std::cin >> op;

        if (op == 1) {
            int L, R, X;
            std::cin >> L >> R >> X;
            Seg.Modify(L, R, Seg.Tag(X, 0, 0));
        } else if (op == 2) {
            int L, R;
            std::cin >> L >> R;
            Seg.Modify(L, R, Seg.Tag(0, 1, 1));
        } else {
            int L, R;
            std::cin >> L >> R;
            auto ans = Seg.Query(L, R).max;
            std::cout << ans << '\n';
        }
    }
    
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

6 6
1 3 5 4
3 2 3
1 1 6 2
2 3 4
3 1 6
3 2 3

4
6
2

2 8
1 1 2 1000000000
1 1 2 1000000000
2 2 2
1 1 2 1000000000
1 1 2 1000000000
1 1 2 1000000000
3 2 2
3 1 2

0
5000000000

24 30
1 11 24 4326
1 4 16 1149
1 14 20 2331
1 12 14 8930
1 22 23 6989
3 15 20
3 10 19
1 3 12 7988
1 18 23 8450
3 9 19
3 13 15
2 8 15
2 9 14
1 11 17 4062
1 6 15 1721
3 7 13
1 11 20 8541
1 8 10 3748
1 1 17 3252
2 9 23
2 1 23
3 2 22
1 5 23 7468
3 1 12
3 12 19
2 6 24
3 2 14
3 1 15
2 15 19
3 2 14

7806
16736
22393
16736
10858
0
7468
7468
0
0
0


*/
}
/*---------------------------------Algostruggler--------------------------------------*/
signed main() {
#ifdef LOCAL
    freopen("A.in", "r", stdin);
#endif // LOCAL

    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    /*std::cout << std::fixed << std::setprecision(9);
    std::cerr << std::fixed << std::setprecision(9);*/

    int _ = 1;
    //for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}