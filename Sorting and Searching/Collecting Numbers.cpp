#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, ans = 0;
int arr[200005];
int idx[200005];

int32_t main(){
    scanf("%lld", &n);
    for(int i=1;i<=n;i++){
        scanf("%lld", &arr[i]);
        idx[arr[i]] = i;
    }
    int l_bound = INT_MAX;
    for(int i=1;i<=n;i++){
        if(idx[i] < l_bound){
            ans++;
        }
        l_bound = idx[i];
    }
    printf("%lld\n", ans);
}

/*
2 5 3 1
*/