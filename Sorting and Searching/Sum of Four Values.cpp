#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, x, arr[1005];

int32_t main(){
    scanf("%lld %lld", &n, &x);
    for(int i=1;i<=n;i++){
        scanf("%lld", &arr[i]);
    }
    map<int, pair<int, int>> mp;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int sum = arr[i] + arr[j];
            int target = x - sum;
            if(mp.find(target) != mp.end()){
                printf("%lld %lld %lld %lld\n", i, j, mp[target].first, mp[target].second);
                return 0;
            }
        }
        for(int k=i-1;k>=1;k--){
            mp[arr[i]+arr[k]] = {i, k};
        }
    }
    printf("IMPOSSIBLE\n");
}