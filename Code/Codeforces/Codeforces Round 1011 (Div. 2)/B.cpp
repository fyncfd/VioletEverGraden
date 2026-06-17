#define  _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O2")
#include "bits/stdc++.h"
//#include <ext/pb_ds/assoc_container.hpp>

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef __int128 i128;

using namespace std;
//using namespace __gnu_pbds;
template <typename T> 
using pq = std::priority_queue<T>;
template<class T> 
using matrix = std::vector<std::vector<T>>;
template <typename T>
using vec = std::vector<T>;
template <class Key, class Value>
using ump = std::unordered_map<Key, Value>;
template <typename T>
using ust = std::unordered_set<T>;
//template <typename Key, typename Value>
//using hash = __gnu_pbds::gp_hash_table<Key, Value>;

template<class T> concept Signed = std::is_signed_v<T>;
template<class T> concept Unsigned = std::is_unsigned_v<T>;
template<class T> concept Arithmetic = std::is_arithmetic_v<T>;

#define all(x) a.begin(), a.end()
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define red(i, l, r) for (int i = l; i >= r; i--)
#define lop(i, x) for (auto i : x)
/*------------------------------SORT_AND_UNIQUE-------------------------------*/
//#define int long long
const double eps = 1e-9;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr ll mod = 998244353;
constexpr ll MOD = 1e9 + 7;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
constexpr int MAXN = 5e3 + 15;
int n;
int a[MAXN];
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    cin >> n;
    vec<int> a(n);
    bool ok = true;
    vec<int> ans;
    rep(i, 0, n - 1) {
        cin >> a[i];
        if (a[i] != 0) ok = false;
            if (a[i] == 0) ans.push_back(i + 1);
    }

    ust<int> s(a.begin(), a.end());
    int mex = 0;
    while (s.count(mex)) mex++;

    if (mex == 0) {
        cout << "1\n1 " << n << "\n";
    } 
    else if (ok) {
        vec<pair<int, int>> ops;
    int temp = n;
        while (temp > 1) {
            ops.emplace_back(temp - 1, temp);
            temp -= 2;
        }
        if (temp == 1) {
            int m = (n + 1) / 2;
            while (m > 1) {
                ops.emplace_back(1, m);
                m = (m + 1) / 2;
            }
        }
        cout << ops.size() << "\n";
        for (auto& p : ops) {
            cout << p.first << " " << p.second << "\n";
        }
    } 
    else {
        vector<pair<int, int>> ops;
        if (ans.size() >= 2) {
            int l = ans.front();
            int r = ans.back();
            ops.emplace_back(l, r);
            int new_len = n - (r - l);
            ops.emplace_back(1, new_len);
        } 
        else {
            int pos = ans[0];
            if (pos == 1) {
                ops.emplace_back(1, 2);
                ops.emplace_back(1, n - 1);
            } 
            else if (pos == n) {
                ops.emplace_back(n - 1, n);
                ops.emplace_back(1, n - 1);
            } 
            else {
                ops.emplace_back(pos - 1, pos);
                ops.emplace_back(1, n - 1);
            }
        }
        cout << ops.size() << "\n";
        for (auto& p : ops) {
            cout << p.first << " " << p.second << "\n";
        }
    }
    /*return AC*/
/*
Test Sample

6
4
1 2 3 4
5
0 1 0 0 1
6
0 0 0 0 0 0
6
5 4 3 2 1 0
4
0 0 1 1
4
1 0 0 0

1
1 4
2
1 4
1 2
3
1 4
5 6
1 2
2
5 6
1 5
2
1 2
1 3
2
2 4
1 2

1
4
1 2 3 4

1
1 4

1
5
0 0 0 0 0

3
1 3
4 5
1 2

1
6
5 4 3 2 1 0

2
5 6
1 5

1
5
0 0 0 0 1

2
1 4
1 2

1
5
0 0 0 0 0

3
1 3
4 5
1 2

1
5
1 0 1 0 0

2
2 5
1 2

1
5
0 1 1 1 1 

2
1 2
1 4

1
5
1 1 1 1 0

2
4 5
1 4

1
5
0 0 0 0 0

3
1 3
4 5
1 2

1
6
0 0 0 0 0 0

3
1 4
5 6
1 2


*/
}
/*-------------------------------Author_Fd------------------------------------*/
void TestArea();
void TimeTest();
static inline void VioletEverGraden();

signed main() {
#ifdef LOCAL
    freopen("A.in", "r", stdin);
#endif // LOCAL

    /*cout << fixed << setprecision();
    cerr << fixed << setprecision();*/

    std::cin.tie(nullptr) -> 
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);

    int _ = 1;

    for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}
// 0 0 1 0