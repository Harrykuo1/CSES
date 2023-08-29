#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
int32_t main(){
    scanf("%lld %lld", &n, &m);
    printf("%lld\n", (n-1) ^ (m-1));
}