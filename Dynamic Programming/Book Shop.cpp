#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, x;
int weight[1005];
int val[1005];
int dp[100005];

int32_t main(){
    scanf("%lld %lld", &n, &x);
    for(int i=1;i<=n;i++){
        scanf("%lld", &weight[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld", &val[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=x;j>=0;j--){
            if(weight[i] > j){
                break;
            }
            dp[j] = max(dp[j], dp[j-weight[i]] + val[i]);
        }
    }
    printf("%lld\n", dp[x]);
}
