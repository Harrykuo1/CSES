#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    set<int> pos;
    multiset<int> sets;
    int n, m, position;
    scanf("%lld %lld", &n, &m);
    pos.insert(0);
    pos.insert(n);
    sets.insert(n);
    for(int i=0;i<m;i++){
        scanf("%lld", &position);
        auto it1 = pos.upper_bound(position);
        auto it2 = it1--;
        int l = *it1;
        int r = *it2;
        sets.erase(sets.find(r-l));
        sets.insert(position-l);
        sets.insert(r-position);
        pos.insert(position);
        printf("%lld ", *sets.rbegin());
    }
    printf("\n");
}