#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, arr[2000005] = {0}, ans = 0;

int32_t main(){
    scanf("%lld", &n);
    for(int i=1;i<=n;i++){
        scanf("%lld", &arr[i]);
    }
    sort(&arr[1], &arr[1]+n);
    for(int i=1;i<=n;i++){
        if(arr[i] != arr[i-1]){
            ans++;
        }
    }
    printf("%lld\n", ans);
}