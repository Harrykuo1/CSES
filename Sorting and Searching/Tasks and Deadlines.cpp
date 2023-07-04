#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;
struct event{
    int duration, deadline;
    bool operator < (const event &R) const{
        return duration < R.duration;
    } 
};
event arr[200005];

signed main(){
    scanf("%lld", &n);
    for(int i=0;i<n;i++){
        scanf("%lld %lld", &arr[i].duration, &arr[i].deadline);
    }
    sort(arr, arr+n);
    int now = 0, ans = 0;
    for(int i=0;i<n;i++){
        now += arr[i].duration;
        ans += arr[i].deadline - now;
    }
    printf("%lld\n", ans);
}