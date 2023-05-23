#include<bits/stdc++.h>
using namespace std;
#define int long long 

struct edge{
    int u, v, w;
}edgeTmp;

int n, m;

int dsu[100005];

void init(){
    for(int i=0;i<100005;i++){
        dsu[i] = i;
    }
}

int find(int n){
    if(dsu[n] == n){
        return n;
    }
    return dsu[n] = find(dsu[n]);
}

bool isSame(int a, int b){
    return find(a) == find(b);
}

void unions(int a, int b){
    dsu[find(a)] = find(b);
}

bool cmp(edge a, edge b){
    return a.w < b.w;
}


int32_t main(){
    scanf("%lld %lld", &n, &m);
    vector<edge> edges;
    init();
    for(int i=0;i<m;i++){
        scanf("%lld %lld %lld", &edgeTmp.u, &edgeTmp.v, &edgeTmp.w);
        edges.push_back(edgeTmp);
    }
    int sel = 0;
    int ans = 0;
    sort(edges.begin(), edges.end(), cmp);
    for(int i=0;i<edges.size();i++){
        if(sel >= n-1){
            break;
        }
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;
        if(isSame(u, v)){
            continue;
        }
        unions(u, v);
        sel++;
        ans += w;
    }

    if(sel == n-1){
        printf("%lld\n", ans);
    }
    else{
        printf("IMPOSSIBLE\n");
    }
}