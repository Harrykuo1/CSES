#include<bits/stdc++.h>
using namespace std;
#define int long long 

int mod = 1000000007;
int t, a, b, c;

int fastPow(int a, int b, int mod){
    if(b == 0){
        return 1;
    }
    else if(b == 1){
        return a;
    }
    else if(b % 2 == 0){
        return fastPow(a*a%mod, b/2, mod);
    }
    else{
        return a * fastPow(a*a%mod, b/2, mod) % mod;
    }
}

signed main(){
    scanf("%lld", &t);
    while(t--){
        scanf("%lld %lld %lld", &a, &b, &c);
        int tmp = fastPow(b, c, mod-1);
        int ans = fastPow(a, tmp, mod);
        printf("%lld\n", ans);
    }
}