///Author: YololoYo AKA Sajol
 
#include "iostream"
#include "stdio.h"
#include "cmath"
#include "map"
#include "set"
#include "stack"
#include "queue"
#include "cstring"
#include "stdlib.h"
#include "algorithm"
#include "vector"
#include "iomanip"
//#include "bits/stdc++.h"
#define SIZE          10000007
#define REM           998244353
#define PI            2*acos(0.0)
#define PB            push_back
#define MK            make_pair
#define F 			  first
#define S             second
#define L             long
#define LL            long long
#define UL            unsigned long
#define ULL           unsigned long long
using namespace std;
LL bigmod1(LL p,LL e,LL M){
    LL ret=1;
    for(; e > 0; e >>= 1){
 
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (LL)ret;
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
	int a,b;
	cin>>a>>b;
	a+=b;
	cout<<bigmod1(2,a,REM)<<endl;
	return 0;
}
