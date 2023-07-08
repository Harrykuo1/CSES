#include<bits/stdc++.h>
using namespace std;
#define int long long 

int n, m, a, b;
vector<int> graph[100005];
bool visited[100005];
vector<int> path;

void dfs(int now, int pre){
    path.push_back(now);
    if(visited[now]){
        int j = 0;
        while(path[j] != now){
            j++;
        }
        printf("%lld\n", path.size() - j);
        while(j < path.size()){
            printf("%lld ", path[j++]);
        }
        exit(0);
    }
    visited[now] = true;
    for(int i : graph[now]){
        if(i == pre) continue;
        dfs(i, now);
    }
    path.pop_back();
}

int32_t main(){
    memset(visited, false, sizeof(visited));
    scanf("%lld %lld", &n, &m);
    for(int i=0;i<m;i++){
        scanf("%lld %lld", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(visited[i]) continue;
        dfs(i, 0);
    }
    printf("IMPOSSIBLE\n");
}