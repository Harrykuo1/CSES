#include<bits/stdc++.h>
using namespace std;
#define int long long
 
int n;
struct Times{
    int start, end;
    bool operator < (const Times R) const{
        return end < R.end;
    }
};
 
Times arr[200005];
 
int32_t main(){
    scanf("%lld", &n);
    for(int i=0;i<n;i++){
        scanf("%lld %lld", &arr[i].start, &arr[i].end);
    }
    sort(arr, arr+n);
    int now = -1, ans = 0;
    for(int i=0;i<n;i++){
        if(arr[i].start >= now){
            now = arr[i].end;
            ans++;
        }
    }
    printf("%lld\n", ans);
}