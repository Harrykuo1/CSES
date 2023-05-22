#include<bits/stdc++.h>
using namespace std;
#define int long long

#define mod 1000000007

int n;
int dp[1005][1005];
char mp[1005][1005];

bool inRange(int y, int x){
    if(0<=y && y<n && 0<=x && x<n){
        return true;
    }
    return false;
}

int32_t main(){
    scanf("%lld", &n);
    dp[0][0] = 1;
    for(int i=0;i<n;i++){
        scanf("%*[\n]");
        for(int j=0;j<n;j++){
            scanf("%c", &mp[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(inRange(i-1, j) && mp[i][j]!='*'){
                dp[i][j] += dp[i-1][j];
                dp[i][j] %= mod;
            }
            if(inRange(i, j-1) && mp[i][j]!='*'){
                dp[i][j] += dp[i][j-1];
                dp[i][j] %= mod;
            }
        }
    }
    if(mp[0][0] == '*'){
        printf("0\n");
    }
    else{
        printf("%lld\n", dp[n-1][n-1]);
    }
}