#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, num, mx, ans;
int arr[1000005];

int32_t main(){
    scanf("%lld", &n);
    for(int i=0;i<n;i++){
        scanf("%lld", &num);
        mx = max(num, mx);
        arr[num]++;
    }
    for(int i=1;i<=mx;i++){
        int sum = 0;
        for(int j=i;j<=mx;j+=i){
            sum += arr[j];
        }
        if(sum >= 2){
            ans = i;
        }
    }
    printf("%lld\n", ans);
}