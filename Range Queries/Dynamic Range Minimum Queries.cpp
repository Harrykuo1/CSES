#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, q, type, a, b;
int arr[200005];
int rmq[200005*4];

void build(int L, int R, int idx){
    if(L == R){
        rmq[idx] = arr[L];
        return;
    }
    int mid = L + (R - L) / 2;
    build(L, mid, idx*2+1);
    build(mid+1, R, idx*2+2);
    rmq[idx] = min(rmq[idx*2+1], rmq[idx*2+2]);
}

void update(int L, int R, int idx, int target){
    if(L == R){
        rmq[idx] = arr[L];
        return;
    }
    int mid = L + (R - L) / 2;
    if(target <= mid){
        update(L, mid, idx*2+1, target);
    }
    else{
        update(mid+1, R, idx*2+2, target);
    }
    rmq[idx] = min(rmq[idx*2+1], rmq[idx*2+2]);
}

int query(int L, int R, int idx, int l, int r){
    if(L == l && R == r){
        return rmq[idx];
    }
    int mid = L + (R - L) / 2;
    int ans = LLONG_MAX;
    if(r <= mid){
        int tmp = query(L, mid, idx*2+1, l, r);
        ans = min(tmp, ans);
    }
    else if(mid < l){
        int tmp = query(mid+1, R, idx*2+2, l, r);
        ans = min(tmp, ans);
    }
    else{
        ans = min(query(L, mid, idx*2+1, l, mid), query(mid+1, R, idx*2+2, mid+1, r));
    }
    return ans;
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
            arr[a] = b;
            update(0, n, 0, a);
        }
        else{
            int ans = query(0, n, 0, a, b);
            printf("%lld\n", ans);
        }
    }
}