#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, q, x, x2, y, y2;
char mp[1005][1005];
int dp[1005][1005];

int32_t main(){
    scanf("%lld %lld", &n, &q);
    for(int i=1;i<=n;i++){
        scanf("%s", &mp[i][1]);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            if(mp[i][j] == '*'){
                dp[i][j]++;
            }
        }
    }
    while(q--){
        scanf("%lld %lld %lld %lld", &y, &x, &y2, &x2);
        int ymax = max(y, y2);
        int ymin = min(y, y2);
        int xmax = max(x, x2);
        int xmin = min(x, x2);
        int ans = dp[ymax][xmax] - dp[ymin-1][xmax] - dp[ymax][xmin-1] + dp[ymin-1][xmin-1];
        printf("%lld\n", ans);
    }
}