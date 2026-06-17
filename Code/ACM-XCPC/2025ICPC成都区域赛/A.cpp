#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define i64 ll

#define rep(i, l, r, x) for (int i = l; i <= r; i ++)

using i64 = long long;

const i64 inf = 10000000;

void solve() {
    i64 n;
    std::cin >> n;
    std::vector<i64> a(n);
    i64 sum = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i] *= inf;
        sum += a[i];
    }

    i64 k;
    if (sum == 100 * inf) {
        k = 0;
    } else if (sum > 100 * inf){
        k = sum - 100 * inf;
        for (int i = 0; i < n; i++) {
            if (a[i]) {
                i64 x = std::min(k, inf / 2);
                a[i] -= x;
                k -= x;
            }
        }
    } else {
        k = abs(sum - (100 * inf));
        for (int i = 0; i < n; i++) {
            if (a[i] < 100 * inf) {
                i64 x = std::min(k, inf / 2 - 1);
                a[i] += x;
                k -= x;
            }
        }
    }
    if (k) {
        std::cout << "No\n";
    } else {
        std::cout << "Yes\n";
        for (auto x : a) {
            std::cout << x << " ";
        }
        std::cout << "\n";
    }
   /*i64 n;
   cin>>n;
   std::vector<double> a(n+1);
   double sum=0.0;
   int num=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=0)
        {
            num++;
        }
        sum+=a[i];
    }
    double cnt1=0.49999999;
    couble cnt2=0.50
    if(sum==100)
    {
        cout<<"Yes\n";
        for(int i=1;i<=n;i++)
        {
            cout<<a[i]<<" ";
        }cout<<endl;
        return ;
    }
    if(sum<100)
    {
        if((sum+num*cnt1)<sum)
        {
            cout<<"No\n";
            return ;
        }

        for(int i=1;i<=n;i++)
        {

        }
    }*/
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int _ = 1;
     for (std::cin >> _; _; _ --)
        solve();

    return 0;
}


/*
3
4
25 25 25 25
5
25 25 25 26 0
3
0 0 1


Yes
1 1 1 1
Yes
25 25 25 26 0
No

1
3
0 0 100

*/ 