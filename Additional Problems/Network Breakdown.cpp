#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m, k, ans;

pair<int, int> edges[200005];
pair<int, int> breaks[200005];

int dsu[100005];
void init(){
    for(int i=0;i<=n;i++){
        dsu[i] = i;
    }
}

int finds(int n){
    if(dsu[n] == n){
        return n;
    }
    return dsu[n] = finds(dsu[n]);
}

void unions(int a, int b){
    dsu[finds(a)] = finds(b);
}

bool isSame(int a, int b){
    return finds(a) == finds(b);
}

int32_t main(){
    scanf("%lld %lld %lld", &n, &m, &k);
    init();
    for(int i=0;i<m;i++){
        scanf("%lld %lld", &edges[i].first, &edges[i].second);
    }

    set<pair<int, int>> s;
    for(int i=0;i<k;i++){
        scanf("%lld %lld", &breaks[i].first, &breaks[i].second);
        s.insert(breaks[i]);
        swap(breaks[i].first, breaks[i].second);
        s.insert(breaks[i]);
    }

    ans = n;
    for(int i=0;i<m;i++){
        if(s.find(edges[i]) == s.end() && !isSame(edges[i].first, edges[i].second)){
            unions(edges[i].first, edges[i].second);
            ans--;
        }
    }

    stack<int> ansSt;
    for(int i=k-1;i>=0;i--){
        ansSt.push(ans);
        if(!isSame(breaks[i].first, breaks[i].second)){
            unions(breaks[i].first, breaks[i].second);
            ans--;
        }
    }
    while(!ansSt.empty()){
        printf("%lld ", ansSt.top());
        ansSt.pop();
    }
}