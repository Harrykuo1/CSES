#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, arr[2000005], ans = 0;

int32_t main(){
    scanf("%lld", &n);
    for(int i=0;i<n;i++){
        scanf("%lld", &arr[i]);
    }
    for(int i=1;i<n;i++){
        if(arr[i-1] >arr[i]){
            ans += (arr[i-1] - arr[i]);
            arr[i] = arr[i-1];
        }
    }
    printf("%lld\n", ans);
}