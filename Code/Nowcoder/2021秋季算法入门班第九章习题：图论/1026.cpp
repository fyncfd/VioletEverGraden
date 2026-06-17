#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;
const int N=110;
#define PII pair<double,int>

int S,T,A,B,idx=1,Tr[N];//Tr[i]存放第i个城市内的道路费
struct ap{
	double x,y;
	int city,pos;
}aps[N<<2];
vector<ap> city[N];
//添加城市内机场节点
void add(int i,double x1,double x2,double x3,double y1,double y2,double y3){
	city[i].push_back({x1,y1,i,idx});aps[idx]={x1,y1,i,idx};idx++;
	city[i].push_back({x2,y2,i,idx});aps[idx]={x2,y2,i,idx};idx++;
	city[i].push_back({x3,y3,i,idx});aps[idx]={x3,y3,i,idx};idx++;
	double l1,l2,l3,maxl;
	l1=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);l2=(x3-x2)*(x3-x2)+(y3-y2)*(y3-y2);
	l3=(x1-x3)*(x1-x3)+(y1-y3)*(y1-y3);maxl=max(max(l1,l2),l3);
	if(l1==maxl){
		city[i].push_back({(x1+x2-x3),(y2+y1-y3),i,idx});
		aps[idx]={(x1+x2-x3),(y2+y1-y3),i,idx};
		idx++;
	}else if(l2==maxl){
		city[i].push_back({(x2+x3-x1),(y2+y3-y1),i,idx});
		aps[idx]={(x2+x3-x1),(y2+y3-y1),i,idx};
		idx++;
	}else{
		city[i].push_back({(x1+x3-x2),(y1+y3-y2),i,idx});
		aps[idx]={(x1+x3-x2),(y1+y3-y2),i,idx};
		idx++;
	}
}
//计算边权
double calc(int a,int b){
	double res=sqrt((aps[a].x-aps[b].x)*(aps[a].x-aps[b].x)+(aps[a].y-aps[b].y)*(aps[a].y-aps[b].y));
	if(aps[a].city!=aps[b].city){
		res*=T;
	}else{
		res*=Tr[aps[a].city];//Tr[i]存放第i个城市内的道路费
	}
	return res;
}

bool st[N<<2];
double dist[N<<2];
priority_queue<PII,vector<PII>,greater<PII> > q;
//堆优化的dijkstra
void dijkstra(){
	for(ap i:city[A]){
		dist[i.pos]=0;
		q.push({0,i.pos});
	}
	while(q.size()){
		double dis;int t;
		PII cur=q.top();dis=cur.first;t=cur.second;
		q.pop();
		if(st[t]){
			continue;
		}
		st[t]=1;
		for(int c=1;c<=S;c++){
			for(ap j:city[c]){
				if(dist[j.pos]>calc(t,j.pos)+dis){
					dist[j.pos]=calc(t,j.pos)+dis;
					q.push({dist[j.pos],j.pos});
				}
			}
		}
	}
	
	double ans=0x3f3f3f3f;
	for(ap i:city[B]){
		ans=min(ans,dist[i.pos]);
	}
	printf("%.1f",ans);
}
//每组数据的处理（记得初始化！！！）
void solve(){
	idx=1;memset(st,0,sizeof st);
	for(int i=1;i<(N<<2);i++){
		dist[i]=0x3f3f3f3f;
	}
	cin>>S>>T>>A>>B;
	for(int i=1;i<=S;i++){
		double x1,x2,x3,y1,y2,y3;
		cin>>x1>>y1>>x2>>y2>>x3>>y3>>Tr[i];
		city[i].clear();
		add(i,x1,x2,x3,y1,y2,y3);
	}
	
	dijkstra();
}

int n;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		solve();
	}
	return 0;
} 
