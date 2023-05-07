#include<bits/stdc++.h>
using namespace std;
#define int long long

struct node{
    int val=0, tag = 0, size;
    int cnt(){
        return val + tag * size;
    }
};

int n, q, a, b, val, k, mode;
int arr[200005];
node segTree[2000005];

void build(int L, int R, int v){
    segTree[v].size = R - L + 1;
    if(L == R){
        segTree[v].val = arr[L];
        return;
    }
    int mid = (L + R) / 2;
    build(L, mid, v*2+1);
    build(mid+1, R, v*2+2);
    segTree[v].val = segTree[v*2+1].val + segTree[v*2+2].val;
}

void modify(int l, int r, int val, int L, int R, int v){
    if(l==L && r==R){
        segTree[v].tag += val;
        return;
    }
    int mid = (L+R)/2;
    if(r <= mid){
        modify(l, r, val, L, mid, v*2+1);
    }
    else if(mid < l){
        modify(l, r, val, mid+1, R, v*2+2);
    }
    else{
        modify(l, mid, val, L, mid, v*2+1);
        modify(mid+1, r, val, mid+1, R, v*2+2);
    }
    segTree[v].val = segTree[v*2+1].cnt() + segTree[v*2+2].cnt();
}

void push(int v){
    segTree[v*2+1].tag += segTree[v].tag;
    segTree[v*2+2].tag += segTree[v].tag;
    segTree[v].val = segTree[v].cnt();
    segTree[v].tag = 0;
}

int query(int pos, int L, int R, int v){
    if(L==R && L==pos){
        return segTree[v].cnt();
    }
    push(v);
    int mid = (L+R)/2;
    if(pos <= mid){
        return query(pos, L, mid, v*2+1);
    }
    else if(mid < pos){
        return query(pos, mid+1, R, v*2+2);
    }
}

signed main(){
    scanf("%lld %lld", &n, &q);
    for(int i=1;i<=n;i++){
        scanf("%lld", &arr[i]);
    }
    build(0, n, 0);
    while(q--){
        scanf("%lld", &mode);
        if(mode == 1){
            scanf("%lld%lld%lld", &a, &b, &val);
            modify(a, b, val, 0, n, 0);
        }
        else{
            scanf("%lld", &k);
            int ans = query(k, 0, n, 0);
            printf("%lld\n", ans);
        }
    }
}
