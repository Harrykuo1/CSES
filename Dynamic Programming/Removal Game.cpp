#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;
int arr[5005];
int pre[5005];
int dp[5005][5005];

int dfs(int l, int r){
    if(l > r){
        return 0;
    }
    if(dp[l][r] != -1){
        return dp[l][r];
    }
    return dp[l][r] = max(arr[l] + min(dfs(l+2, r), dfs(l+1, r-1)), arr[r] + min(dfs(l, r-2), dfs(l+1, r-1)));
}

int32_t main(){
    memset(dp, -1, sizeof(dp));
    scanf("%lld", &n);
    for(int i=1;i<=n;i++){
        scanf("%lld", &arr[i]);
    }
    int ans = dfs(1, n);
    printf("%lld\n", ans);
}