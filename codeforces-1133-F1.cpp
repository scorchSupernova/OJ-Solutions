#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,e,u,v;
vector<LL> vv[2*100005];
bool vis[2*100005];
void bfs(LL str){
    vis[str]=true;
    queue<LL> q;
    q.push(str);
    while(!q.empty()){
        int vk=q.front();
        //cout<<vk<<" ";
        q.pop();
        for(LL i=0;i<vv[vk].size();i++){
            if(!vis[vv[vk][i]]){
                    cout<<vk<<" "<<vv[vk][i]<<endl;
                vis[vv[vk][i]]=true;
                q.push(vv[vk][i]);
            }
        }
    }
}
int main(){
    cin>>n>>e;
    while(e--){
        cin>>u>>v;
        vv[u].push_back(v);
        vv[v].push_back(u);
    }
    memset(vis,false,sizeof(vis));
    LL mx=0;
    LL id;
    for(LL i=1;i<=n;i++){
        if(vv[i].size()>mx){
            mx=vv[i].size();
            id=i;
            //break;
        }
    }
    bfs(id);
    return 0;
}
