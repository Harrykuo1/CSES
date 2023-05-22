#include<bits/stdc++.h>
using namespace std;
#define int long long

#define mod 1000000007

int dp[10000005];

int32_t main(){

    int n, x, num;
    scanf("%lld %lld", &n, &x);
    vector<int> vec;
    for(int i=0;i<n;i++){
        scanf("%lld", &num);
        vec.push_back(num);
        dp[num] = 1;
    }

    for(int i=0;i<=x;i++){
        for(int j=0;j<n;j++){
            if(i<vec[j]){
                continue;
            }
            dp[i] += dp[i-vec[j]];
            dp[i] %= mod;
        }
    }
    printf("%lld\n", dp[x]);
}
