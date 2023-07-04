#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, q, type, a, b;
int arr[200005];
int seg[200005*4];

void build(int L, int R, int idx){
    if(L == R){
        seg[idx] = arr[L];
        return;
    }
    int mid = L+(R-L)/2;
    build(L, mid, idx*2+1);
    build(mid+1, R, idx*2+2);
    seg[idx] = seg[idx*2+1] + seg[idx*2+2];
}

void modify(int target, int val, int L, int R, int idx){
    if(L == R && L == target){
        seg[idx] = val;
        return;
    }
    int mid = L+(R-L)/2;
    if(target <= mid){
        modify(target, val, L, mid, idx*2+1);
    }
    else{
        modify(target, val, mid+1, R, idx*2+2);
    }
    seg[idx] = seg[idx*2+1] + seg[idx*2+2];
}

int query(int l, int r, int L, int R, int idx){
    if(l == L && r == R){
        return seg[idx];
    }
    int mid = L+(R-L)/2;
    if(r <= mid){
        return query(l, r, L, mid, idx*2+1);
    }
    else if(mid < l){
        return query(l, r, mid+1, R, idx*2+2);
    }
    else{
        return query(l, mid, L, mid, idx*2+1) + query(mid+1, r, mid+1, R, idx*2+2);
    }
}

int32_t main(){
    scanf("%lld %lld", &n, &q);
    for(int i=1;i<=n;i++){
        scanf("%lld", &arr[i]);
    }
    build(0, n, 0);
    while(q--){
        scanf("%lld %lld %lld", &type, &a, &b);
        if(type == 1){
            modify(a, b, 0, n, 0);
        }
        else{
            int ans = query(a, b, 0, n, 0);
            printf("%lld\n", ans);
        }
    }
}