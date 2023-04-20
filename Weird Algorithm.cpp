#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int n;
    scanf("%lld", &n);
    while(1){
        printf("%lld ", n);
        if(n == 1){
            break;
        }
        if(n % 2){
            n = 3 * n + 1;
        }
        else{
            n /= 2;
        }
    }
}