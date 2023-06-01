#include<bits/stdc++.h>
using namespace std;
#define int long long

int dp[1000005], n;

int32_t main(){
    memset(dp, 0x3f, sizeof(dp));
    scanf("%lld", &n);
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        int tmp = i;
        while(tmp){
            int now = tmp % 10;
            dp[i] = min(dp[i], dp[i-now]+1);
            tmp /= 10;
        }
    }
    printf("%lld\n", dp[n]);
}