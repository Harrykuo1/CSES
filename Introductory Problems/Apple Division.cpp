#include<bits/stdc++.h>
using namespace std;
#define int long long 

int arr[1000];

int32_t main(){
    int n, total = 0;
    scanf("%lld", &n);
    for(int i=0;i<n;i++){
        scanf("%lld", &arr[i]);
        total += arr[i];
    }
    int ans = INT_MAX;
    for(int i=0;i<(1<<n);i++){
        int tmp = 0;
        for(int j=0;j<n;j++){
            if(i & (1<<j)){
                tmp += arr[j];
            }
        }
        ans = min(ans, abs(total-2*tmp));
    }
    printf("%lld\n", ans);
}