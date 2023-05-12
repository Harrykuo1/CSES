#include<bits/stdc++.h>
using namespace std;
#define int long long

int t, a, b; 
int mod = 1000000007;

int myPow(int a, int b){
    if(b == 0){
        return 1;
    }
    else if(b == 1){
        return a;
    }
    else if(b % 2 == 0){
        return myPow(a*a%mod, b/2);
    }
    else{
        return a * myPow(a*a%mod, b/2) % mod;
    }
}

signed main(){
    scanf("%lld", &t);
    while(t--){
        scanf("%lld %lld", &a, &b);
        int ans = myPow(a, b);
        printf("%lld\n", ans);
    }
}
