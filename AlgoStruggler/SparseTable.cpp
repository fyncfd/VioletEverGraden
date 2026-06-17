#include "bits/stdc++.h"

using i64 = long long;
using i128 = __int128;
 
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;

/*
* @Author: AlgoStruggler
* SparseTable 不带修解决重复贡献问题。
* 最大值、最小值、最大公因数、最小公倍数、按位或、按位与。
* @Create Time: 2026-02-01 22:24:41
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
* 愿幸运女神与最纯粹的前行者同在。
*/
template <typename Info, typename T>
class SparseTable {
private:
    int N;
    std::vector<std::vector<Info>> ST;
    std::vector<int> log2;
public:
    SparseTable() : N(0) {}

    SparseTable(const std::vector<T> &arr) {
        N = (int)arr.size() - 1;

        log2.resize(N + 1);
        log2[1] = 0;
        for (int i = 2; i <= N; i++) {
            log2[i] = log2[i / 2] + 1;
        }
        
        int K = log2[N] + 1;
        ST.resize(K, std::vector<Info>(N + 1));

        for (int i = 1; i <= N; i ++) {
            ST[0][i] = Info(arr[i]);
        }
        for (int j = 1; j < K; j ++) {
            for (int i = 1; i + (1 << j) - 1 <= N; i ++) {
                ST[j][i] = ST[j - 1][i] + ST[j - 1][i + (1 << (j - 1))];
            }
        }
    }

    Info Query(int l, int r) {
        int j = log2[r - l + 1];
        Info res = ST[j][l] + ST[j][r - (1 << j) + 1];
        return res;
    }
};
struct Info {
    i64 max;
    i64 min;
    i64 gcd;
    Info() : 
    max(std::numeric_limits<i64>::min()), 
    min(std::numeric_limits<i64>::max()), 
    gcd(0) {}
    Info(i64 val) : 
    max(val), 
    min(val), 
    gcd(val) {}
};

Info operator + (const Info &a, const Info &b) {
    Info res;
    res.max = std::max(a.max, b.max);
    res.min = std::min(a.min, b.min);
    res.gcd = std::gcd(a.gcd, b.gcd);
    return res;
}

void VioletEverGraden() {
    int N, M;
    std::cin >> N >> M;

    std::vector<i64> a(N + 1);
    for (int i = 1; i <= N; i ++) {
        std::cin >> a[i];
    }

    SparseTable<Info, i64> ST(a);
    int __ = M;
    while (__ --) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int l, r;
            std::cin >> l >> r;
            i64 ans = ST.Query(l, r).min;
            std::cout << ans << '\n';
        } else {
            int l, r;
            std::cin >> l >> r;
            i64 ans = ST.Query(l, r).max;
            std::cout << ans << '\n';
        }
    }

/*
Test Sample
测试数据来自:https://www.nowcoder.com/practice/831a314449d44ea0b1db90ca626bcd1a?tpId=388&tqId=11078067&channelPut=tracker1

6 4
1 1 4 5 1 4
1 1 1
1 3 4
2 4 4
2 1 6

1
4
5
5


*/
}

signed main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    int _ = 1;
    // for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}