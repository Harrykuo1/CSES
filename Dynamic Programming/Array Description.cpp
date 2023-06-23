#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007

int n, m, now;
int dp[100005][105];

int32_t main(){
    scanf("%lld %lld", &n, &m);
    scanf("%lld", &now);
    if(now){
        dp[0][now] = 1;
    }
    else{
        for(int i=1;i<=m;i++){
            dp[0][i] = 1;
        }
    }

    for(int i=1;i<n;i++){
        scanf("%lld", &now);
        if(now){
            dp[i][now] += (dp[i-1][now-1] + dp[i-1][now] + dp[i-1][now+1]);
            dp[i][now] %= mod;
        }
        else{
            for(int j=1;j<=m;j++){
                dp[i][j] += (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]);
                dp[i][j] %= mod;
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=m;i++){
        ans += dp[n-1][i];
        ans %= mod;
    }
    printf("%lld\n", ans);
}