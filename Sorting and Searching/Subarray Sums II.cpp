#include<bits/stdc++.h>
using namespace std;
#define int long long 

int n, x, num;

int32_t main(){
    scanf("%lld %lld", &n, &x);
    map<int, int> mp;
    mp[0] = 1;
    int sum = 0, ans = 0;
    for(int i=0;i<n;i++){
        scanf("%lld", &num);
        sum += num;
        ans += mp[sum - x];
        mp[sum]++;
    }
    printf("%lld\n", ans);
}