#include<bits/stdc++.h>
using namespace std;
#define int long long

char arr[10000];
char brr[10000];
int len1, len2, dp[5005][5005];

int32_t main(){
    scanf("%s", &arr[1]);
    scanf("%s", &brr[1]);
    len1 = strlen(&arr[1]);
    len2 = strlen(&brr[1]);
    for(int i=1;i<5005;i++){
        dp[0][i] = i;
        dp[i][0] = i;
    }
    for(int i=1;i<=len1;i++){
        for(int j=1;j<=len2;j++){
            dp[i][j] = dp[i-1][j-1];
            if(arr[i] != brr[j]) dp[i][j]++;
            dp[i][j] = min(dp[i][j], min(dp[i-1][j], dp[i][j-1])+1);
        }
    }
    printf("%lld\n", dp[len1][len2]);
}