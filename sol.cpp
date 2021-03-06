#include "bits/stdc++.h"
#define SIZE          100005
#define REM           1000000007
#define PI            2*acos(0.0)
#define L             long
#define LL            long long
#define UL            unsigned long
#define ULL           unsigned long long
#define TERMINATE     return 0
#define FAST          ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
template <class T> inline T bigmod1(T p,T e,T M){
    LL ret=1;
    for(; e > 0; e >>= 1){
 
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
 
template <class T> inline T gcode(T a,T b){if(b==0)return a;return gcode(b,a%b);}
template <class T> inline T modularinv(T a,T M){return bigmod1(a,M-2,M);}
 
bool SA(const pair<string,string> &a, const pair<string,string> &b){
   return a.second<b.second;
}
bool FA(const pair<string,string> &a, const pair<string,string> &b){
   return a.first<b.first;
}
bool SD(const pair<LL,LL> &a, const pair<LL,LL> &b){
   return a.second>b.second;
}
bool FD(const pair<int,int> &a, const pair<int,int> &b){
   return a.first>b.first;
}
//int dirA[8]={0,0,1,-1,1,-1,1,-1};
//int dirB[8]={1,-1,0,0,1,-1,-1,1};
//int dirA[4]={0,0,1,-1};
//int dirB[4]={1,-1,0,0};
//int kingsA[8]={0,0,1,-1,-1,1,-1,1};  //Kings Move
//int kingsB[8]={-1,1,0,0,1,1,-1,-1};  //Kings Move
//int knightsA[8]={-2,-2,-1,-1,1,1,2,2};  //Knights Move
//int knightsB[8]={-1,1,-2,2,-2,2,-1,1};  //Knights Move
 
vector<LL> adj[SIZE];
bool vis[SIZE];
LL par[SIZE];
map<LL,LL> node,mp;
set<LL> stt;

void dfs(LL str){
	vis[str]=true;
	par[str]=-1;
	stack<LL> st;
	st.push(str);
	LL cnt=0;
	while(!st.empty()){
		int tt=st.top();
		st.pop();
		cnt++;
		node[tt]=cnt;
		mp[cnt]=tt;
		if(adj[tt].size()==0){
			stt.insert(node[tt]);
		}
		else if(adj[tt].size()==1){
			LL child=adj[tt][0];
			if(!vis[child]){
				vis[child]=true;
				par[child]=tt;
				st.push(child);
			}
			else{
				stt.insert(node[tt]);
			}
		}
		else{
			for(LL i=0;i<adj[tt].size();i++){
				LL child=adj[tt][i];
				if(!vis[child]){
					par[child]=tt;
					vis[child]=true;
					st.push(child);
				}
			}
		}
	}
}
int main(){
	FAST;
	//freopen("test.in","r",stdin);
	int t,tt=1;
	scanf("%d",&t);
	while(t--){
		LL n;
		map<LL,int> deg;
		map<LL,bool> check;
		scanf("%lld",&n);
		for(LL i=0;i<n-1;i++){
			LL a,b;
			scanf("%lld%lld",&a,&b);
			deg[a]++;
			deg[b]++;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		for(LL i=1;i<=n;i++){
			sort(adj[i].rbegin(),adj[i].rend());
		}
		dfs(1);
		for(LL i=1;i<=n;i++){
			vis[i]=false;
			adj[i].clear();
		}
		//cout<<deg[1]<<endl;
		LL q;
		scanf("%lld",&q);
		printf("Case %d:\n",tt++);
		while(q--){
			LL x;
			scanf("%lld",&x);
			if(x==1){
				LL v;
				LL y;
				scanf("%lld%lld",&v,&y);
				if(!check[v]){
				set<LL>::iterator it;
				for(LL i=0;i<y;i++){
					it=stt.lower_bound(node[v]);
					stt.erase(it);
					LL val=mp[*it];
					check[val]=true;
					if(*it==node[v]){
						deg[par[val]]--;
						if(par[val]==1){
							if(deg[par[val]]==0) stt.insert(1);
						}
						else{
						if(deg[par[val]]==1) stt.insert(node[par[val]]);}
						break;
					}
					else{
						deg[par[val]]--;
						if(par[val]==1){
							if(deg[par[val]]==0) stt.insert(1);
						}
						else{
						if(deg[par[val]]==1) stt.insert(node[par[val]]);}
					}
					if(stt.size()==0) break;
				}
			  }
				
			}
			if(x==2){
				LL v;
				scanf("%lld",&v);
				if(check[v]){
					printf("1\n");
				}
				else printf("0\n");
			}
		}
		stt.clear();
		node.clear();
		mp.clear();

	}
	//cerr<<"time elapsed:"<<clock()*1000.0/CLOCKS_PER_SEC<<"ms"<<"\n";
	return 0;
}