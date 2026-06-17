/*
* @Author: AlgoStruggler
* @Create Time: 2025-06-04 13:17:44
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
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;

//using namespace std;
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

#define all(x) x.begin() + 1, x.end()
#define LLA(x) (x).rbegin(), (x).rend()
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define red(i, l, r) for (int i = l; i >= r; i--)
#define lop(i, x) for (auto i : x)
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
std::string s;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> s;

    std::map<char, int> hash;
    hash['A'] = 1; hash['B'] = 2; hash['C'] = 0; hash['D'] = 1;
    hash['E'] = 0; hash['F'] = 0; hash['G'] = 0; hash['H'] = 0;
    hash['I'] = 0; hash['J'] = 0; hash['K'] = 0; hash['L'] = 0;
    hash['M'] = 0; hash['N'] = 0; hash['O'] = 1; hash['P'] = 1;
    hash['Q'] = 1; hash['R'] = 1; hash['S'] = 0; hash['T'] = 0;
    hash['U'] = 0; hash['V'] = 0; hash['W'] = 0; hash['X'] = 0;
    hash['Y'] = 0; hash['Z'] = 0;
//FIREINTHEHOLE
    int ans = -1; int temp = 0;
    //int flag = 0;
    rep(i, 0, 30) {
    	temp = 0; //flag ++;
    	rep(j, 0, s.size() - 1) {
    		int x = s[j] - 'A';
    		x = (x + i) % 26;
    		char c = x + 'A';
    		temp += hash[c];
    		//std::cerr << s[j] << '\n';
    	} 

    	//std::cerr << s << '\n';

/*    	rep(k, 0, s.size() - 1) {
    		temp += hash[s[k]];
    		//std::cout << hash[s[k]] << " \n"[k == s.size() - 1];
    	}*/

    	ans = std::max(ans, temp);
    }

    std::cout << ans << '\n';
    /*return AC*/
/*
Test Sample

FIREINTHEGHOLE

10

FIREINTHEHOLE

9

BBBBBBBBBB

20

CCCCCCCCCC

20

AAAAAAAAAA

20


*/
}
/*-------------------------------Author_Fd------------------------------------*/
static inline void VioletEverGraden();

auto __INIT__ = []() {
    std::cin.tie(nullptr) ->
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
};

signed main() {
#ifdef LOCAL
    freopen("A.in", "r", stdin);
#endif // LOCAL

    /*cout << std::fixed << std::setprecision();
    cerr << std::fixed << std::setprecision();*/


    __INIT__();

    int _ = 1;

    //for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}