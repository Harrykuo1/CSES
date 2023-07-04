#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, t, ans = INT_MAX;
int l, r, mid;
int arr[200005];

bool check(int times){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += times/arr[i];
        if(sum >= t){
            return true;
        }
    }
    return false;
}

signed main(){
    scanf("%lld%lld", &n, &t);
    for(int i=0;i<n;i++){
        scanf("%lld", &arr[i]);
    }
    l = 1, r = LLONG_MAX-1;
    while(l <= r){
        mid = l + (r - l) / 2;
        if(check(mid)){
            ans = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    printf("%lld\n", ans);
}