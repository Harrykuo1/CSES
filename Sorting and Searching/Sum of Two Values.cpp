#include<bits/stdc++.h>
using namespace std;
#define int long long
 
int n, x;
int arr[200005];
 
int32_t main(){
    map<int, int> mp;
    scanf("%lld %lld", &n, &x);
    for(int i=0;i<n;i++){
        scanf("%lld", &arr[i]);
    }
    for(int i=0;i<n;i++){
        int target = x - arr[i];
        if(mp.find(target) != mp.end()){
            printf("%lld %lld\n", mp[target], i+1);
            exit(0);
        }
        mp[arr[i]] = i+1;
    }
    printf("IMPOSSIBLE\n");
}