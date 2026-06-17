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

#define all(x) x.begin() + 1, x.end()
#define LLA(x) (x).rbegin(), (x).rend()
#define pb push_back
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
int n;
int b, e; std::string s1, s2;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> s;
    std::cin >> n;

    while (n --) {
    	std::cin >> b >> e >> s1 >> s2;
    	std::string t;
    	t = s.substr(b - 1, e - b + 1);
    	s.erase(b - 1, e - b + 1);

    	int pos1 = s.find(s1) + s1.size(); int pos2 = s.find(s2);
    	std::string t1, t2;
    	rep(i, 0, pos1 - 1) {
    		t1.push_back(s[i]);
    	}
    	rep(i, pos2, s.size() - 1) {
    		t2.push_back(s[i]);
    	}
    	s = t1 + t + t2;
    }

    std::cout << s << '\n';
    /*return AC*/
/*
Test Sample

*/
}
/*-------------------------------Author_Fd------------------------------------*/
static inline void VioletEverGraden();

auto __INIT__ = []() {
    std::cin.tie(nullptr) ->
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
};
int main()
{
	string s;cin>>s;
	int n;cin>>n;
	while(n--)
	{
		int a,b;cin>>a>>b;
		a--,b--;
		string c,d;cin>>c>>d;
		string temp=s.substr(a,b-a+1);
		string check=c+d;
		s.erase(a,b-a+1);
		int pos=s.find(check);
		if(pos==-1) s+=temp;
		else
		{
			string t=s.substr(0,pos+c.size())+temp+s.substr(pos+c.size());
			s=t;
		}
	}
	cout<<s;
	
    return 0;
}
