#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, x, l, r, mid, ans;
int arr[200005];

bool check(int limit){
    int group = 1, sum = 0;
    for(int i=0;i<n;i++){
        if(sum + arr[i] > limit){
            sum = 0;
            group++;
        }
        sum += arr[i];
    }
    if(group <= x){
        return true;
    }
    return false;
}

int32_t main(){
    scanf("%lld %lld", &n, &x);
    for(int i=0; i<n; i++){
        scanf("%lld", &arr[i]);
        l = max(arr[i], l);
        r += arr[i];
    } 
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