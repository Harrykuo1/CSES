#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007

int t, n;
int dp[2][1000005];

int32_t main(){
    dp[0][1] = 1LL;
    dp[1][1] = 1LL;
    for(int i=2;i<=1000000;i++){
        dp[0][i] = dp[0][i-1] * 2 + dp[1][i-1];
        dp[0][i] %= mod;
        dp[1][i] = dp[0][i-1] + dp[1][i-1] * 4;
        dp[1][i] %= mod;
    }
    scanf("%lld", &t);
    while(t--){
        scanf("%lld", &n);
        int ans = (dp[0][n] + dp[1][n]) % mod;
        printf("%lld\n", ans);
    }
}