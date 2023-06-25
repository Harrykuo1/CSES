#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, ans;
int arr[200005];
int dp[200005];

int32_t main(){
    scanf("%lld", &n);
    for(int i=1;i<=n;i++){
        scanf("%lld", &arr[i]);
    }
    ans = arr[1];
    for(int i=1;i<=n;i++){
        dp[i] = max(dp[i-1]+arr[i], arr[i]);
        ans = max(ans, dp[i]);
    }
    printf("%lld\n", ans);
}