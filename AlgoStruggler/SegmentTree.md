# SegmentTree
#### **愿幸运女神与最纯粹的前行者同在。**

将维护的信息整合到 $Info$ 内，在维护信息的时候用面向对象的思想，重载 $+$ 运算符，达到 $push\_up$ 的复用性。维护的信息必须满足**结合律**。

在维护 $Lazy\_tag$ 的时候，所有的 $tag$ 信息都整合在 $tag$ 内，每次增加维护的信息的时候，只需要**修改 $Addtag$** 就能达到维护的目的。

$Update$ 和 $Modify$ 函数的参数列表里传了 $tag$ 类型的参数，保证了复用性，我们只需要传不同的 $tag$ 就可以用同一个 $Update$ 和 $Modify$ 完成所有的操作类型。

$Query$ 的返回值是 $Info$ 类型，这样提高了 $Query$ 的复用性，在遇到不同问题的时候 $Update$ ， $Modify$ 和 $Query$ 都是不用修改的。

在维护多 $tag$ 的时候，要注意每个 $tag$ 的 **优先级**。 

模板适用于常规的加法和、最小值、最大值、区间反转、字符串哈希等，特征为：对 $Query$的合并是 $ O(1)/O(logn) $ 的。

模板把数据的操作全部交给 $Info$ 自行计算并合并，然后即可在 $Query$ 中取出。**线段树本身不理解 $Info$ 中存储的数据**。


```cpp{.line-numbers}
/*
* SgementTree + Lazy_tag Info, tag类型支持拓展操作。
* @Author: AlgoStruggler
* @Create Time: 2026-01-27 17:06:11
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#include "bits/stdc++.h"

using i64 = long long;

template <typename T>
class SegmentTree {
private:
    int N;
    std::vector<T> a;

    struct Info {
        i64 sum;
        Info(i64 s = 0) : sum(s) {}

        Info operator + (const Info &a) const {
            Info res;
            res.sum = sum + a.sum;
            return res;
        }
    };
    std::vector<Info> Seg;

    struct tag {
        i64 add;
        tag(i64 a = 0) : add(a) {}
    };
    std::vector<tag> Lazy;

    void push_up(i64 id) {
        Seg[id] = Seg[id << 1] + Seg[id << 1 | 1];
    }

    void Build(i64 id, i64 l, i64 r) {
        Lazy[id] = {0};
        if (l == r) {
            Seg[id] = {a[l]};
        } else {
            i64 mid = l + r >> 1;
            Build(id << 1, l, mid);
            Build(id << 1 | 1, mid + 1, r);
            push_up(id);
        }
    }

    void Addtag(i64 id, i64 l, i64 r, const tag &v) {
        Seg[id].sum += v.add * (r - l + 1);
        Lazy[id].add += v.add;
    }

    void push_down(i64 id, i64 l, i64 r) {
        if (Lazy[id].add) {
            i64 mid = l + r >> 1;
            Addtag(id << 1, l, mid, Lazy[id]);
            Addtag(id << 1 | 1, mid + 1, r, Lazy[id]);
            Lazy[id] = {0};
        }
    }

    void Update(i64 id, i64 l, i64 r, i64 pos, const tag &v) {
        if (l == r) {
            Seg[id].sum += v.add;
            return ;
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
            Addtag(id, l, r, v.add);
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

    tag Tag(i64 val) {
        return tag(val);
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

void VioletEverGraden() {
    int n, m;
    std::cin >> n >> m;

    std::vector<i64> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        std::cin >> a[i];
    }

    SegmentTree<i64> Seg(a);
    int __ = m;
    while (__ --) {
        int op;
        std::cin >> op;

        if (op == 1) {
            int l, r, k;
            std::cin >> l >> r >> k;
            Seg.Modify(l, r, Seg.Tag(k));
        } else {
            int l, r;
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
```