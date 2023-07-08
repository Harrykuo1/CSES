#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod (int)1e9+7
 
int n, tmp;
int dp[500000];
 
int32_t main(){
    scanf("%lld", &n);
    int target = (n+1)*n/2;
    if(target % 2){
        printf("0\n");
        return 0;
    }
    target /= 2;
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=target;j>=i;j--){
            dp[j] += dp[j-i];
            if(j == target){
                tmp = dp[j];
            }
            dp[j] %= mod;
        }
    }
    printf("%lld\n", tmp/2);
}