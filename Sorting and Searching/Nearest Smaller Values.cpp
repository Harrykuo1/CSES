#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, num;
int arr[200005];
int dp[200005];

int32_t main(){
    scanf("%lld", &n);
    for(int i=1;i<=n;i++){
        scanf("%lld", &arr[i]);
        int pos = i-1;
        while(arr[pos] >= arr[i]){
            pos = dp[pos];
        }
        dp[i] = pos;
        printf("%lld ", dp[i]);
    }
    printf("\n");
}