#define  _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O2")
#include "bits/stdc++.h"

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef __int128 i128;

using namespace std;
template <typename T> 
using pq = std::priority_queue<T>;
template<class T> 
using matrix = std::vector<std::vector<T>>;
template <typename T>
using vec = std::vector<T>;

template<class T> concept Signed = std::is_signed_v<T>;
template<class T> concept Unsigned = std::is_unsigned_v<T>;
template<class T> concept Arithmetic = std::is_arithmetic_v<T>;

#define rep(i, l, r) for (int i = l; i <= r; i++)
#define red(i, l, r) for (int i = l; i >= r; i--)
#define lop(i, x) for (auto i : x)
#define all(x) a.begin(), a.end()
/*------------------------------SORT_AND_UNIQUE-------------------------------*/
//#define int long long
const double eps = 1e-9;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr ll mod = 998244353;
constexpr ll MOD = 1e9 + 7;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
constexpr int MAXN = 0;
int n;
std::string s;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> n;
    std::cin >> s;
    s = " " + s;

    vec<int> s1(s.size() + 1), s0(s.size() + 1);

    rep(i, 1, s.size() - 1) {
        if (s[i] == '1') {
            s1[i] = s1[i - 1] + 1;
            s0[i] = s0[i - 1];
        }
        else {
            s0[i] = s0[i - 1] + 1;
            s1[i] = s1[i - 1];
        }
    }

    vec<int> id;
        rep(i, 0, n) {
            int c1 = s0[i], c2 = s1[n] - s1[i];
            int x = c1 + c2;
            if ( x >= (n + 1) / 2 and c1 >= (i + 1) / 2 and c2 >= (n - i + 1) / 2) {
                id.push_back(i);
            } 
        }
        db x = n * 1.0 / 2;
        db res = inf;
        int d = 0;
        lop(i, id) {
            if (abs(x - i) < res) {
                res = abs(x - i);
                d = i;
            } 
            else if(abs(x - i) == res) {
                if (d > i) {
                    d = i;
                }
            }
        }

    std::cout << d << '\n';
    //debug();
/*
7
3
101
6
010111
6
011001
3
000
3
110
3
001
4
1100

2
3
2
3
0
1
0
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
        VioletEverGraden(); //TimeTest();

    return 0;
}