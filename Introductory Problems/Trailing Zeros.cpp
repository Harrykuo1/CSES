#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int n, ans = 0;
    scanf("%lld", &n);
    while(n >= 5){
        ans += n/5;
        n /= 5;
    }
    printf("%lld\n", ans);
}