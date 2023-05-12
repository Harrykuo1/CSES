#include<bits/stdc++.h>
using namespace std;
#define int long long
 
struct node{
    int val=0, tag = 0, size, setVal;
    bool setValValid = false;
    int cnt(){
        if(setValValid){
            return size * (setVal + tag);
        }
        else{
            return val + tag * size;
        }
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

void push(int v){
    if(segTree[v].setValValid){
        segTree[v*2+1].setVal = segTree[v].setVal;
        segTree[v*2+1].setValValid = true;
        segTree[v*2+2].setVal = segTree[v].setVal;
        segTree[v*2+2].setValValid = true;
        segTree[v*2+1].tag = segTree[v].tag;
        segTree[v*2+2].tag = segTree[v].tag;
    }
    else{
        segTree[v*2+1].tag += segTree[v].tag;
        segTree[v*2+2].tag += segTree[v].tag;
    }
    segTree[v].val = segTree[v].cnt();
    segTree[v].tag = 0;
    segTree[v].setValValid = false;
}
 
void increase(int l, int r, int val, int L, int R, int v){
    if(l==L && r==R){
        segTree[v].tag += val;
        return;
    }
    push(v);
    int mid = (L+R)/2;
    if(r <= mid){
        increase(l, r, val, L, mid, v*2+1);
    }
    else if(mid < l){
        increase(l, r, val, mid+1, R, v*2+2);
    }
    else{
        increase(l, mid, val, L, mid, v*2+1);
        increase(mid+1, r, val, mid+1, R, v*2+2);
    }
    segTree[v].val = segTree[v*2+1].cnt() + segTree[v*2+2].cnt();
}
 
void setVal(int l, int r, int val, int L, int R, int v){
    if(l==L && r==R){
        segTree[v].setVal = val;
        segTree[v].setValValid = true;
        segTree[v].tag = 0;
        return;
    }
    push(v);
    int mid = (L+R)/2;
    if(r <= mid){
        setVal(l, r, val, L, mid, v*2+1);
    }
    else if(mid < l){
        setVal(l, r, val, mid+1, R, v*2+2);
    }
    else{
        setVal(l, mid, val, L, mid, v*2+1);
        setVal(mid+1, r, val, mid+1, R, v*2+2);
    }
    segTree[v].val = segTree[v*2+1].cnt() + segTree[v*2+2].cnt();
}
 
int query(int l, int r, int L, int R, int v){
    if(l==L && r==R){
        return segTree[v].cnt();
    }
    push(v);
    int mid = (L+R)/2;
    if(r <= mid){
        return query(l, r, L, mid, v*2+1);
    }
    else if(mid < l){
        return query(l, r, mid+1, R, v*2+2);
    }
    else{
        return query(l, mid, L, mid, v*2+1) + query(mid+1, r, mid+1, R, v*2+2);
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
            increase(a, b, val, 0, n, 0);
        }
        else if(mode == 2){
            scanf("%lld%lld%lld", &a, &b, &val);
            setVal(a, b, val, 0, n, 0);
        }
        else{
            scanf("%lld%lld", &a, &b);
            int ans = query(a, b, 0, n, 0);
            printf("%lld\n", ans);
        }
    }
}