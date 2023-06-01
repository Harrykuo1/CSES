#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m, a, b;

bool visited[100005];

void dfs(vector<vector<int>> &edges, int id){
    if(visited[id]){
        return;
    }
    visited[id] = true;
    for(auto x:edges[id]){
        dfs(edges, x);
    }
}

int32_t main(){
    scanf("%lld %lld", &n, &m);
    vector<vector<int>> edges(n+5);
    vector<vector<int>> inverse_edges(n+5);
    for(int i=0;i<m;i++){
        scanf("%lld %lld", &a, &b);
        edges[a].push_back(b);
        inverse_edges[b].push_back(a);
    }
    memset(visited, false, sizeof(visited));
    dfs(edges, 1);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            printf("NO\n1 %lld\n", i);
            return 0;
        }
    }
    memset(visited, false, sizeof(visited));
    dfs(inverse_edges, 1);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            printf("NO\n%lld 1\n", i);
            return 0;
        }
    }
    printf("YES\n");
}