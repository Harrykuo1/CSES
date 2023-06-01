#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m, a, b;

int32_t main(){
    scanf("%lld %lld", &n, &m);
    for(int i=0;i<m;i++){
        scanf("%lld %lld", &a, &b);
        if(a > b){
            int tmp = a;
            a = b;
            b = tmp;
        }
        printf("%lld %lld\n", a, b);
    }
}