#include<bits/stdc++.h>
using namespace std;
#define int long long

int a, b;
int dp[1000][1000];

int32_t main(){
    memset(dp, 0x3f, sizeof(dp));
    scanf("%lld %lld", &a, &b);
    for(int i=0;i<1000;i++){
        dp[i][i] = 0;
        dp[0][i] = 0;
        dp[i][0] = 0;
    }
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            for(int k=1;k<i;k++){
                dp[i][j] = min(dp[i][j], dp[k][j]+dp[i-k][j]+1);
            }
            for(int k=1;k<j;k++){
                 dp[i][j] = min(dp[i][j], dp[i][k]+dp[i][j-k]+1);
            }
        }
    }
    printf("%lld\n", dp[a][b]);
}