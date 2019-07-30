#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int one=0,two=0,th=0,fr=0;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a==1) one++;
        if(a==2) two++;
        if(a==3) th++;
        if(a==4) fr++;
    }
    LL cnt=0;
    if(one<=th){
        LL v=(one*3);
        v+=one;
        th-=one;
        if(v%4){
            cnt+=(v/4)+1;
        }
        else cnt+=(v/4);
        cnt+=th;
        LL v1=(two*2);
        if(v1%4){
            cnt+=(v1/4)+1;
        }
        else cnt+=(v1/4);
        cnt+=fr;
    }
    else{
        LL v=(th);
        v+=(th*3);
        one-=th;
        if(v%4){
            cnt+=(v/4)+1;
        }
        else cnt+=(v/4);
        LL v1=(two*2)+one;
        if(v1%4){
            cnt+=(v1/4)+1;
        }
        else cnt+=(v1/4);
        cnt+=fr;
    }
    cout<<cnt<<endl;
    return 0;
}
