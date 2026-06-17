#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
int main()
{
    map<string,ll>mp;
    int x;
    while(cin>>x)
    {
        if(x==1)
        {
            string s;
            int sco;
            cin>>s>>sco;
            mp[s]=sco;
            cout<<"OK"<<endl;
        }
        if(x==2)
        {
            string s;
            cin>>s;
            map<string,ll>::iterator it=mp.find(s);
            if(it!=mp.end())
            {
                cout<<mp[s]<<endl;
                
            }
            else
            {
                cout<<"Not found"<<endl;
            }
        }
        if(x==3)
        {
            string s;
            cin>>s;
            map<string,ll>::iterator it=mp.find(s);
            if(it!=mp.end())
            {
                mp.erase(s);
                cout<<"Deleted successfully"<<endl;
                
            }
            else
            {
                cout<<"Not found"<<endl;
            }
        }
        if(x==4)
        {
            cout<<mp.size()<<endl;
        }
    }
    return 0;
}