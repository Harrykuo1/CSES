#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, ans = 0;
int arr[200005];

bool cmp(int a, int b){
    return a < b;
}

int32_t main(){
    scanf("%lld", &n);
    for(int i=0;i<n;i++){
        scanf("%lld", &arr[i]);
    }
    sort(arr, arr+n, cmp);
    int mid = arr[n/2];
    for(int i=0;i<n;i++){
        ans += llabs(arr[i] - mid);
    }
    printf("%lld\n", ans);
}