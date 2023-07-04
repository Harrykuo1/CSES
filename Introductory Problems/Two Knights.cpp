#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;

int32_t main() {
    scanf("%lld", &n);
    printf("0\n");
    for(int i=2;i<=n;i++){
        int ans = (i*i) * (i*i-1) / 2 - (4 * (i-2) * (i-1));
        printf("%lld\n", ans);
    }
}