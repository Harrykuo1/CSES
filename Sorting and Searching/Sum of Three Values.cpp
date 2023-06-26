#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, x;
int arr[5005];
map<int, int> mp;
set<int> s;

int32_t main(){
    scanf("%lld %lld", &n ,&x);
    for(int i=1;i<=n;i++){
        scanf("%lld", &arr[i]);
        mp[arr[i]] = i;
        s.insert(arr[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int target = x - arr[i] - arr[j];
            if(s.find(target) != s.end()){
                if(i != j && i != mp[target] && j != mp[target]){
                    printf("%lld %lld %lld\n", i, j, mp[target]);
                    exit(0);
                }
                
            }
        }
    }
    printf("IMPOSSIBLE\n");
}