#include<bits/stdc++.h>
using namespace std;
int main(){
    int l,r,a1,b1,c1,a2,b2,c2;
    cin>>l>>r;
    if(l%3==0){
        a1=l/3;
        b1=l/3;
        c1=l/3;
        std::cerr << "??\n";
        cout<<a1<<" "<<b1<<" "<<c1<<endl;
    } 
    if(l%3==1){
        a1=l/3+1;
        b1=l/3;
        c1=l/3;
        cout<<a1<<" "<<b1<<" "<<c1<<endl;
    }
    if(l%3==2){
       a1=l/3+1;
       b1=l/3+1;
       c1=l/3;
       cout<<a1<<" "<<b1<<" "<<c1<<endl;
    } 
    // cout<<a1<<" "<<b1<<" "<<c1<<endl;
    if(r%3==0){
        a2=r/3;
        b2=r/3;
        c2=r/3;
        std::cerr << "??\n";
        cout<<a2<<" "<<b2<<" "<<c2<<endl;
    } 
    if(r%3==1){
        a2=r/3+1;
        b2=r/3;
        c2=r/3;
        cout<<a2<<" "<<b2<<" "<<c2<<endl;
    }
    if(r%3==2){
       a2=r/3+1;
       b2=r/3+1;
       c2=r/3;
       cout<<a2<<" "<<b2<<" "<<c2<<endl;
    } 
    // cout<<a2<<" "<<b2<<" "<<c2<<endl;
   
  
   
     
   
   
}