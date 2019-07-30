#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
 
int main(){
    LL a,b;
    scanf("%lld%lld",&a,&b);
    LL pow[a];
    vector<pair<LL,LL> > v;
    for(LL i=0;i<a;i++) {
        scanf("%lld",&pow[i]);
    }
    while(b--){
        LL x,y;
         scanf("%lld%lld",&x,&y);
        v.push_back(make_pair(x,y));
    }
    vector<LL> cum,val;
    sort(v.begin(),v.end());
    val.push_back(v[0].first);
    cum.push_back(v[0].second);
    for(LL i=1;i<v.size();i++){
        val.push_back(v[i].first);
        cum.push_back(v[i].second+cum[cum.size()-1]);
    }
   // for(LL i=0;i<val.size();i++) cout<<val[i]<<" ";
    //cout<<endl;
    int index;
   for(LL i=0;i<a;i++){
        if(binary_search(val.begin(),val.end(),pow[i])){
            index=lower_bound(val.begin(),val.end(),pow[i])-val.begin();
            cout<<cum[index]<<" ";
        }
        else{
             index=lower_bound(val.begin(),val.end(),pow[i])-val.begin();
             if(index-1<0)cout<<0<<" ";
             else
             cout<<cum[index-1]<<" ";
        }
   }
    return 0;
}
