#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, num;
struct Event{
    int time, value=1;
    bool operator < (const Event R) const{
        return time < R.time;
    }
};

Event arr[200005*2];

int32_t main(){
    scanf("%lld", &n);
    for(int i=0;i<n;i++){
        scanf("%lld", &num);
        arr[i*2].time = num;
        scanf("%lld", &num);
        arr[i*2+1].time = num;
        arr[i*2+1].value = -1;
    }
    sort(arr, arr+(n*2));
    int ans = 0, now = 0;
    for(int i=0;i<n*2;i++){
        now += arr[i].value;
        ans = max(ans, now);
    }
    printf("%lld\n", ans);
}