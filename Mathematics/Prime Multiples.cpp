#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, k, ans;
int arr[25];

int32_t main(){
    scanf("%lld %lld", &n, &k);
    for(int i=0;i<k;i++){
        scanf("%lld", &arr[i]);
    }
    for(int mask=1;mask<(1<<k);mask++){
        bool odd = __builtin_popcount(mask)&1;
        int now = n;
        for(int i=0;i<k;i++){
            if(mask & (1<<i)){
                now /= arr[i];
            }
        }
        ans += odd ? now : (-1)*now;
    }
    printf("%lld\n", ans);
}