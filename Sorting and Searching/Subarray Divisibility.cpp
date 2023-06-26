#include<bits/stdc++.h>
using namespace std;
#define int long long 

int n, num;

int32_t main(){
    scanf("%lld", &n);
    map<int, int> mp;
    mp[0] = 1;
    int sum = 0, ans = 0;
    for(int i=0;i<n;i++){
        scanf("%lld", &num);
        sum += num;
        ans += mp[(sum+n*100000000)%n];
        mp[(sum+n*100000000)%n]++;
    }
    printf("%lld\n", ans);
}