#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, q, num, a, b;
int arr[200005];

int32_t main(){
    scanf("%lld %lld", &n, &q);
    for(int i=1;i<=n;i++){
        scanf("%lld", &num);
        arr[i] = arr[i-1] ^ num;
    }
    while(q--){
        scanf("%lld %lld", &a, &b);
        printf("%lld\n", arr[b] ^ arr[a-1]);
    }
}