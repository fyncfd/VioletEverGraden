/*
* @Author: AlgoStruggler
* @Create Time: 2025-08-01 20:18:28
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

using namespace std;
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
ll x, y;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
const int MAX_N = 1e6 + 10;
vector<int> min_prime(MAX_N, 0);
void sieve() {
    for (int i = 2; i < MAX_N; ++i) {
        if (min_prime[i] == 0) {
            min_prime[i] = i;
            for (int j = i + i; j < MAX_N; j += i) {
                if (min_prime[j] == 0) {
                    min_prime[j] = i;
                }
            }
        }
    }
}
static inline void VioletEverGraden() {
    long long X, Y;
    cin >> X >> Y;
    long long A = X * Y;
    vector<pair<long long, int>> factors;

    if (A != 1) {
        long long temp = A;
        if (temp < MAX_N) {
            while (temp != 1) {
                int p = min_prime[temp];
                int count = 0;
                while (temp % p == 0) {
                    count++;
                    temp /= p;
                }
                factors.emplace_back(p, count);
            }
        } else {
            int count = 0;
            while (temp % 2 == 0) {
                count++;
                temp /= 2;
            }
            if (count > 0) {
                factors.emplace_back(2, count);
            }
            for (long long i = 3; i * i <= temp; i += 2) {
                count = 0;
                while (temp % i == 0) {
                    count++;
                    temp /= i;
                }
                if (count > 0) {
                    factors.emplace_back(i, count);
                }
            }
            if (temp > 1) {
                factors.emplace_back(temp, 1);
            }
        }
    }

    int b = 1;
    if (!factors.empty()) {
        b = factors[0].second;
        for (size_t i = 1; i < factors.size(); ++i) {
            b = __gcd(b, factors[i].second);
        }
    }

    long long a = 1;
    for (const auto& [prime, exp] : factors) {
        a *= pow(prime, exp / b);
    }

    cout << a << " " << b << "\n";
    /*太好了，这回只花998244353min就打完了！*/
/*
Test Sample

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
    sieve();
    int _ = 1;
    for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}