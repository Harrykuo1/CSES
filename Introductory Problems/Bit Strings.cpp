#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;

int32_t main(){
    scanf("%lld", &n);
    int ans = 1;
    for(int i=0;i<n;i++){
        ans *= 2;
        ans %= 1000000007;
    }
    printf("%lld\n", ans);
}
