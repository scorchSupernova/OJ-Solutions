
#include "bits/stdc++.h"
#define SIZE          10000007
#define REM           1000000007
#define PI            2*acos(0.0)
#define PB            push_back
#define MK            make_pair
#define F         first
#define S             second
#define L             long
#define LL            long long
#define UL            unsigned long
#define ULL           unsigned long long
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

bool SA(const pair<int,int> &a, const pair<int,int> &b){
   return a.second<b.second;
}
bool FA(const pair<int,int> &a, const pair<int,int> &b){
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

void Khela_Hobe(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
}
/*void Khela_Hok(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
}*/

int main(){
  //Khela_Hok();
  Khela_Hobe();
  int t;
  cin>>t;
  while(t--){
    LL a,b;
    cin>>a>>b;
    string s;
    cin>>s;
    int lens=s.length();
    char ar[b]={'0'},ar1[b]={'0'},ar2[b]={'0'};
    for(int i=0;i<b;i+=3) ar[i]='R';
    for(int i=1;i<b;i+=3) ar[i]='G';
    for(int i=2;i<b;i+=3) ar[i]='B';
    for(int i=0;i<b;i+=3) ar1[i]='B';
    for(int i=1;i<b;i+=3) ar1[i]='R';
    for(int i=2;i<b;i+=3) ar1[i]='G';
    for(int i=0;i<b;i+=3) ar2[i]='G';
    for(int i=1;i<b;i+=3) ar2[i]='B';
    for(int i=2;i<b;i+=3) ar2[i]='R';
      vector<LL> v;
    for(int i=0;i<lens;i++){
      int cnt=0,cnt1=0,cnt2=0;
      for(int j=i,k=0;j<=i+b,k<b;j++,k++){
        if(s[j]!=ar[k]){
          cnt++;
        }
      }
      v.push_back(cnt);
      for(int j=i,k=0;j<=i+b,k<b;j++,k++){
        if(s[j]!=ar1[k]){
          cnt1++;
        }
      }
      v.push_back(cnt1);
      for(int j=i,k=0;j<=i+b,k<b;j++,k++){
        if(s[j]!=ar2[k]){
          cnt2++;
        }
      }
      v.push_back(cnt2);

    }
    cout<<*min_element(v.begin(),v.end())<<endl;
  }
  return 0;
}
