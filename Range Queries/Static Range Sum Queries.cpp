#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, q, l, r;
int arr[200005], segTree[2000005];

int build(int L, int R, int v){
    if(L == R){
        segTree[v] = arr[L];
        return segTree[v];
    }
    int mid = (L + R) / 2;
    return segTree[v] = build(L, mid, v * 2 + 1) + build(mid + 1, R, v * 2 + 2);
}

int query(int l, int r, int L, int R, int v){
    if(l==L && r==R){
        return segTree[v];
    }
    int mid = (L + R) / 2;
    if(r <= mid){
        return query(l, r, L, mid, v * 2 + 1);
    }
    else if(mid < l){
        return query(l, r, mid + 1, R, v * 2 + 2);
    }
    else{
        return query(l, mid, L, mid, v * 2 + 1) + query(mid + 1, r, mid + 1, R, v * 2 + 2);
    }
}

signed main(){
    scanf("%lld %lld", &n, &q);
    arr[0] = 0;
    for(int i=1;i<=n;i++){
        scanf("%lld", &arr[i]);
    }
    build(0, n, 0);
    while(q--){
        scanf("%lld %lld" ,&l, &r);
        int ans = query(l ,r, 0, n, 0);
        printf("%lld\n", ans);
    }
}