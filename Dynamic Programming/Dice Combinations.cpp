#include<bits/stdc++.h>
using namespace std;
#define int long long 

#define mod 1000000007

int dp[10000005];

signed main(){
    int n;
    scanf("%lld", &n);
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6 && j<=i;j++){
            dp[i] += dp[i-j];
            dp[i] %= mod;
        }
    }
    printf("%lld\n", dp[n]);
}
