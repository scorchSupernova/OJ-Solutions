#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int sz=100005;

double ar[3*sz];
double tree[3*sz];
void init(int node, int b, int e)
{
    if (b == e) {
        tree[node] = ar[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node] = tree[Left] + tree[Right];
}
double query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return 0;
    if (b >= i && e <= j)
        return tree[node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    double p1 = query(Left, b, mid, i, j);
    double p2 = query(Right, mid + 1, e, i, j);
    return p1 + p2;
}
void update(int node, int b, int e, int i, double newvalue)
{
    if (i > e || i < b)
        return;
    if (b >= i && e <= i) {
        tree[node] = newvalue;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    tree[node] = tree[Left] + tree[Right];
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%lf",&ar[i]);
    }
    init(1,0,n-1);
    int q;
    scanf("%d",&q);
    while(q--){
        int a;
        scanf("%d",&a);
        if(a==1){
            int x;
        double y;
        scanf("%d%lf",&x,&y);
            update(1,0,n-1,x-1,y);
        }
        else{
                int m,nn;
                scanf("%d%d",&m,&nn);
            double que=query(1,0,n-1,m-1,nn-1);
            double v=(que/(nn-m+1.0));
            printf("%.6lf\n",v);
        }
    }
    return 0;
}
