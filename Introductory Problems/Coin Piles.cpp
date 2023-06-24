#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int t, a, b, sum;
    scanf("%lld", &t);
    while(t--){
        scanf("%lld %lld", &a, &b);
        int doubleSmall = min(a, b) * 2;
        int big = max(a, b);
        a += b;
        if(a % 3 == 0 && (doubleSmall>= big)){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
}