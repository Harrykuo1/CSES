#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, a, b, startID, maxDis = -1, maxID = -1;
vector<vector<int>> graph;
vector<bool> visited;

void dfs(int now, int dis){
    visited[now] = true;
    if(maxDis < dis){
        maxDis = dis;
        maxID = now;
    }
    for(int i : graph[now]){
        if(visited[i]) continue;
        dfs(i, dis+1);
    }
}

int32_t main(){
    scanf("%lld", &n);
    graph.resize(n+1);
    for(int i=1;i<n;i++){
        scanf("%lld %lld", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    visited.assign(n+1, false);
    dfs(1, 0);

    startID = maxID;
    maxDis = -1, maxID = -1;
    visited.assign(n+1, false);
    dfs(startID, 0);
    printf("%lld\n", maxDis);
}