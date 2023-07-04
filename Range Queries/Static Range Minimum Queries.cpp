#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, q, a, b;
int arr[200005];
int rmq[200005*4];

void build(int L, int R, int idx){
    if(L == R){
        rmq[idx] = arr[L];
        return;
    }
    int mid = L+(R-L)/2;
    build(L, mid, idx*2+1);
    build(mid+1, R, idx*2+2);
    rmq[idx] = min(rmq[idx*2+1], rmq[idx*2+2]);
}

int query(int l, int r, int L, int R, int idx){
    if(l == L && r == R){
        return rmq[idx];
    }
    int mid = L+(R-L)/2;
    if(r <= mid){
        return query(l, r, L, mid, idx*2+1);
    }
    else if(mid < l){
        return query(l, r, mid+1, R, idx*2+2);
    }
    else{
        return min(query(l, mid, L, mid, idx*2+1), query(mid+1, r, mid+1, R, idx*2+2));
    }
}

int32_t main(){
    scanf("%lld %lld", &n, &q);
    for(int i=1;i<=n;i++){
        scanf("%lld", &arr[i]);
    }
    build(0, n, 0);
    while(q--){
        scanf("%lld %lld", &a, &b);
        int ans = query(a, b, 0, n, 0);
        printf("%lld\n", ans);
    }
}