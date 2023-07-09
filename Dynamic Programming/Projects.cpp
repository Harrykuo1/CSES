#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long

int n, st, ed, w;

struct Project{
    int st, ed, w;
    bool operator < (const Project &R) const{
        return ed < R.ed;
    }
};

Project arr[200005];

int32_t main(){
    scanf("%lld", &n);
    for(int i=0;i<n;i++){
        scanf("%lld %lld %lld", &st, &ed, &w);
        arr[i] = {st, ed, w};
    }
    sort(arr, arr+n);
    map<int, int> mp;
    mp[0] = 0LL;
    for(int i=0;i<n;i++){
        st = arr[i].st; ed = arr[i].ed; w = arr[i].w;
        auto pre = --mp.lower_bound(st);
        auto pos = --mp.upper_bound(ed);
        mp[ed] = max((*pre).second + w, (*pos).second);
    }
    printf("%lld\n", (*(--mp.end())).second);
}