#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, q, num;
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
    rmq[idx] = max(rmq[idx*2+1], rmq[idx*2+2]);
}

int query(int target, int L, int R, int idx){
    if(L == R){
        rmq[idx] -= target;
        return L;
    }
    int ans;
    int mid = L + (R - L) / 2;
    if(rmq[idx*2+1] >= target){
        ans =  query(target, L, mid, idx*2+1);
    }
    else{
        ans =  query(target, mid+1, R, idx*2+2);
    }
    rmq[idx] = max(rmq[idx*2+1], rmq[idx*2+2]);
    return ans;
}

int32_t main(){
    scanf("%lld %lld", &n, &q);
    for(int i=1;i<=n;i++){
        scanf("%lld", &arr[i]);
    }
    build(0, n, 0);
    while(q--){
        scanf("%lld", &num);
        if(rmq[0] >= num){
            printf("%lld ", query(num, 0, n, 0));
        }
        else{
            printf("0 ");
        }

    }
}