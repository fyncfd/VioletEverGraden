/*
* @Author: AlgoStruggler
* @Create Time: 2025-11-08 14:04:01
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#define  _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O2")
#include "bits/stdc++.h"
//#include <ext/pb_ds/assoc_container.hpp>

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef __int128 i128;
struct pii { int fi; int se; };
struct pll { ll fi; ll se; };

#define all(x) x.begin() + 1, x.end()
#define rep(i, l, r, x) for (decltype(l) i = (l); i <= (r); i += (x))
#define dep(i, l, r, x) for (decltype(l) i = (l); i >= (r); i -= (x))
#define lop(i, x) for (auto &i : x)

//using namespace std;
//using namespace __gnu_pbds;
template<class T> using matrix = std::vector<std::vector<T>>;
template <typename T> using pq = std::priority_queue<T>;
template<class T> using matrix = std::vector<std::vector<T>>;
template <class Key, class Value> using ump = std::unordered_map<Key, Value>;
template <typename T> using ust = std::unordered_set<T>;
//template <typename Key, typename Value> using hash = __gnu_pbds::gp_hash_table<Key, Value>;
template<class T> concept Signed = std::is_signed_v<T>;
template<class T> concept Unsigned = std::is_unsigned_v<T>;
template<class T> concept Arithmetic = std::is_arithmetic_v<T>;
template<class T> std::istream &operator >> (std::istream &cin, std::vector<T> &a) {
    rep(i, 1, a.size() - 1, 1) {
        std::cin >> a[i];
    }
    return cin;
}
template<class T> std::ostream &operator << (std::ostream &cout, std::vector<T> &a) {
    int n = a.size() - 1;
    if (!n) {
        return cout;
    }
    rep(i, 1, a.size() - 1, 1) {
        std::cout << a[i] << " \n"[i == a.size() - 1];
    }
    return cout;
}
template<class T> std::istream &operator >> (std::istream &cin, matrix<T> &a) {
    rep(i, 1, a.size() - 1, 1) {
        rep(j, 1, a[i].size() - 1, 1) {
            cin >> a[i][j];
        }
    }
    return cin;
}
template<class T> std::ostream &operator << (std::ostream &cout, const matrix<T> &a) {
    if (a.empty()) {
        return cout;
    }
    rep(i, 1, a.size() - 1, 1) {
        rep(j, 1, a[i].size() - 1, 1) {
            cout << a[i][j] << " \n"[j == a[i].size() - 1];
        }
    }
    return cout;
}
/*------------------------------SORT_AND_UNIQUE-------------------------------*/
//#define int long long
const double eps = 1e-9;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3f;
constexpr ll mod = 998244353;
constexpr ll MOD = 1e9 + 7;
int dx[] = {0, 0, 1, 0, -1 };
int dy[] = {0, -1, 0, 1, 0 };
constexpr int MAXN = 0;
std::string n;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> n;

    bool ok = true;
    int l = 0, r = n.length() - 1;
    while (l < r) {
        if (n[l] != n[r]) {
            ok = false;
            break;
        }
        l ++; r --;
    }
    
    if (ok) {
        std::cout << 0 << '\n';
        return ;
    }
    
    int len = n.length();
    std::string half = n.substr(0, (len + 1) / 2);
    
    std::string temp = half;
    for (int i = len / 2 - 1; i >= 0; i--) {
        temp += half[i];
    }
    
    bool ok2 = false;
    if (temp.length() != n.length()) {
        ok2 = temp.length() < n.length();
    } else {
        ok2 = temp <= n;
    }
    
    if (ok2) {
        std::string ns = half;
        int pp = 1;
        for (int i = ns.length() - 1; i >= 0 && pp; i--) {
            int dig = ns[i] - '0' + pp;
            ns[i] = dig % 10 + '0';
            pp = dig / 10;
        }
        if (pp) ns = "1" + ns;
        
        temp = ns;
        dep(i, len / 2 - 1, 0, 1) {
            temp += ns[i];
        }
    }
    
    std::string m;
    int q = 0;
    int i = temp.length() - 1, j = n.length() - 1;
    
    while (i >= 0 || j >= 0) {
        int x = (i >= 0) ? temp[i] - '0' : 0;
        int y = (j >= 0) ? n[j] - '0' : 0;
        int dif = x - y - q;
        if (dif < 0) {
            dif += 10;
            q = 1;
        } else {
            q = 0;
        }
        m.push_back(dif + '0');
        i --; j --;
    }
    
    while (m.length() > 1 && m.back() == '0') {
    	m.pop_back();
    }
    reverse(m.begin(), m.end());
    
    std::cout << m << '\n';
    /*太好了，这回只花998244353min就打完了！*/
/*
Test Sample

114514

997

113311

0


*/
}
/*-------------------------------Author_Fd------------------------------------*/
static inline void VioletEverGraden();

auto __FAST_IO__ = []() -> int {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    return 0;
}();

signed main() {
#ifdef LOCAL
    freopen("A.in", "r", stdin);
#endif // LOCAL

    /*std::cout << std::fixed << std::setprecision(9);
    std::cerr << std::fixed << std::setprecision(9);*/

    int _ = 1;
    //for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}