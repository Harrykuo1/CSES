#include<bits/stdc++.h>
using namespace std;

#define int long long

int count(int n){
    return n * (n+1) / 2;
}

int32_t main(){
    int n, num;
    scanf("%lld", &n);
    int ans = count(n);
    for(int i=0;i<n-1;i++){
        scanf("%lld", &num);
        ans -= num;
    }
    printf("%lld\n", ans);
}