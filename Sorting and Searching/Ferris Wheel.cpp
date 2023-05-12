#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m, ans = 0;
int arr[2000005] = {0};

int32_t main(){
    scanf("%lld%lld", &n, &m);
    for(int i=0;i<n;i++){
        scanf("%lld", &arr[i]);
    }
    sort(arr, arr + n);
    int l=0, r=n-1;
    while(l<=r){
        if(arr[r] + arr[l] <= m){
            l++;
        }
        r--;
        ans++;
    }
    printf("%lld\n", ans);
}