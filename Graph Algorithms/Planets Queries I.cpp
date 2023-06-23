#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAX 35

int n, q, x, k;
int table[200005][MAX];

int32_t main(){
    scanf("%lld %lld", &n, &q);
    for(int i=1;i<=n;i++){
        scanf("%lld", &table[i][0]);
    }

    for(int i=1;i<MAX;i++){
        for(int j=1;j<=n;j++){
            table[j][i] = table[table[j][i-1]][i-1];
        }
    }

    while(q--){
        scanf("%lld %lld", &x, &k);
        int ans = x;
        for(int i=0;i<MAX;i++){
            if(k & (1LL<<i)){
                ans = table[ans][i];
            }
        }
        printf("%lld\n", ans);
    }
}