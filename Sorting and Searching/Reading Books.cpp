#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, num, sum, mx;

int32_t main(){
    scanf("%lld", &n);
    while(n--){
        scanf("%lld", &num);
        sum += num;
        mx = max(num, mx);
    }
    if(mx * 2 >= sum){
        printf("%lld\n", mx * 2);
    }
    else{
        printf("%lld\n", sum);
    }
}